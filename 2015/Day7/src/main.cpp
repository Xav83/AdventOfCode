#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <regex>
#include <cctype>

enum class OperationType
{
    AND, // x AND y -> z
    OR, // x OR y -> z
    LSHIFT, // x LSHIFT 2 -> y
    RSHIFT, // x RSHIFT 2 -> y
    NOT, // NOT x -> y
    ATTRIBUTION, // 123 -> x
};

OperationType getOperationFromInstruction (const std::string& instruction)
{
    if(instruction.find("AND") != std::string::npos)
    {
        return OperationType::AND;
    }
    else if(instruction.find("OR") != std::string::npos)
    {
        return OperationType::OR;
    }
    else if(instruction.find("LSHIFT") != std::string::npos)
    {
        return OperationType::LSHIFT;
    }
    else if(instruction.find("RSHIFT") != std::string::npos)
    {
        return OperationType::RSHIFT;
    }
    else if(instruction.find("NOT") != std::string::npos)
    {
        return OperationType::NOT;
    }
    else
    {
        return OperationType::ATTRIBUTION;
    }
}

using Signal = uint16_t;

class Wire
{
public:
    explicit Wire (const std::string& name_) : name(name_) {}
    ~Wire () = default;

    bool operator==(const Wire& other) const
    {
        return name == other.name;
    }

    bool hasSignal () const { return hasSignalValueBeenSet; }

    Signal getSignal() const { return value; }

    void setSignal(const Signal value_)
    {
        value = value_;
        hasSignalValueBeenSet = true;
    }

    std::string getName() const { return name; }

private:
    std::string name;
    bool hasSignalValueBeenSet{false};
    Signal value{0};
};

class Wires
{
public:
    Wires () = default;
    ~Wires () = default;

    void addNewWire(const Wire& wire)
    {
        auto found = std::any_of(std::begin(wires), std::end(wires), [&wire](const auto& wireElement)
        {
            return wire == wireElement;
        });
        if(!found)
        {
            wires.emplace_back(wire);
        }
    }

    std::vector<Wire>& getWires()
    {
        return wires;
    }

    Wire& getWireRef(const Wire& w)
    {
        auto element = std::find(std::begin(wires), std::end(wires), w);
        assert(element != std::end(wires));
        return *element;
    }

private:
    std::vector<Wire> wires;
};

Signal getSignalFromInstruction (const std::string& instruction)
{
    std::regex word_regex("[0-9]+");
    auto words_begin = std::sregex_iterator(std::begin(instruction), std::end(instruction), word_regex);
    auto words_end = std::sregex_iterator();

    auto value{0};

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        return static_cast<Signal>(atoi(match.str().c_str()));
    }
    assert (false);
    return 0;
}

Wires getWiresNameInInstruction (const std::string& instruction)
{
    std::regex word_regex("([a-z]+)");
    auto words_begin = std::sregex_iterator(std::begin(instruction), std::end(instruction), word_regex);
    auto words_end = std::sregex_iterator();

    Wires wires;

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        wires.addNewWire(Wire(match.str()));
    }
    return wires;
}

class Operation
{
public:
    explicit Operation (Wire& output_) : output(output_) {}
    ~Operation () = default;

    Wire& getResultWire () { return output; }
    virtual bool canBeExecuted () const = 0;
    virtual bool isExecuted () const = 0;
    virtual void execute () = 0;

protected:
    Wire &output;
};

class And : public Operation
{
public:
    And (Wire& input1_, Wire& input2_, Wire& output_) : Operation(output_), input_wire(&input1_), input2(input2_) { }
    And (Signal input1_, Wire& input2_, Wire& output_) : Operation(output_), input_signal(input1_), input2(input2_) { }
    ~And () = default;

    bool canBeExecuted () const override
    {
        if(input_wire == nullptr)
        {
            return input2.hasSignal();
        }
        return input_wire->hasSignal() && input2.hasSignal();
    }

    bool isExecuted () const override
    {
        return hasBeenExecuted;
    }

    void execute () override
    {
        if(input_wire == nullptr)
        {
            output.setSignal (input_signal & input2.getSignal());
        }
        else
        {
            output.setSignal (input_wire->getSignal() & input2.getSignal());
        }
        
        hasBeenExecuted = true;
    }

private:
    Wire* input_wire{nullptr},& input2;
    Signal input_signal{0};
    bool hasBeenExecuted{false};
};

class Or : public Operation
{
public:
    Or (Wire& input1_, Wire& input2_, Wire& output_) : Operation(output_), input1(input1_), input2(input2_) {}
    ~Or () = default;

    bool canBeExecuted () const override
    {
        return input1.hasSignal() && input2.hasSignal();
    }

    bool isExecuted () const override
    {
        return hasBeenExecuted;
    }

    void execute () override
    {
        output.setSignal (input1.getSignal() | input2.getSignal());
        hasBeenExecuted = true;
    }

private:
    Wire& input1, &input2;
    bool hasBeenExecuted{false};
};

class LShift : public Operation
{
public:
    LShift (Wire& input_, size_t number_, Wire& output_) : Operation(output_), input(input_), number(number_) {}
    ~LShift () = default;

    bool canBeExecuted () const override
    {
        return input.hasSignal();
    }

    bool isExecuted () const override
    {
        return hasBeenExecuted;
    }

    void execute () override
    {
        output.setSignal (input.getSignal() << number);
        hasBeenExecuted = true;
    }

private:
    Wire& input;
    size_t number{0};
    bool hasBeenExecuted{false};
};

class RShift : public Operation
{
public:
    RShift (Wire& input_, size_t number_, Wire& output_) : Operation(output_), input(input_), number(number_) {}
    ~RShift () = default;

    bool canBeExecuted () const override
    {
        return input.hasSignal();
    }

    bool isExecuted () const override
    {
        return hasBeenExecuted;
    }

    void execute () override
    {
        output.setSignal (input.getSignal() >> number);
        hasBeenExecuted = true;
    }

private:
    Wire& input;
    size_t number{0};
    bool hasBeenExecuted{false};
};

class Not : public Operation
{
public:
    Not (Wire& input_, Wire& output_) : Operation(output_), input(input_) { }
    ~Not () = default;

    bool canBeExecuted () const override
    {
        return input.hasSignal();
    }

    bool isExecuted () const override
    {
        return hasBeenExecuted;
    }

    void execute () override
    {
        output.setSignal (~input.getSignal());
        hasBeenExecuted = true;
    }

private:
    Wire& input;
    bool hasBeenExecuted{false};
};

class Attribution : public Operation
{
public:
    Attribution (Signal input_, Wire& output_) : Operation(output_), input_signal(input_) {}
    Attribution (Wire& input_, Wire& output_) : Operation(output_), input_wire(&input_) {}
    ~Attribution () = default;

    bool canBeExecuted () const override
    {
        if(input_wire == nullptr)
        {
            return true;
        }
        else 
        {
            return input_wire->hasSignal();
        }
    }

    bool isExecuted () const override
    {
        return hasBeenExecuted;
    }

    void execute () override
    {
        if(input_wire == nullptr)
        {
            output.setSignal (input_signal);
        }
        else 
        {
            output.setSignal (input_wire->getSignal());
        }

        hasBeenExecuted = true;
    }

private:
    Wire* input_wire{nullptr};
    Signal input_signal{0};
    bool hasBeenExecuted{false};
};

class Operations
{
public:
    Operations () = default;
    ~Operations () = default;

    void addNewOperation(OperationType type, Wires& wires, Wires& wiresFromInstruction, const std::string& instruction)
    {
        switch (type)
        {
        case OperationType::AND:
        {
            if(std::isdigit(instruction.front()))
            {
                auto input1 = getSignalFromInstruction (instruction);
                auto& input2 = wires.getWireRef(wiresFromInstruction.getWires()[0]);
                auto& output = wires.getWireRef(wiresFromInstruction.getWires()[1]);
                operations.emplace_back(std::make_unique<And>(input1, input2, output));
            }
            else
            {
                auto& input1 = wires.getWireRef(wiresFromInstruction.getWires()[0]);
                auto& input2 = wires.getWireRef(wiresFromInstruction.getWires()[1]);
                auto& output = wires.getWireRef(wiresFromInstruction.getWires()[2]);
                operations.emplace_back(std::make_unique<And>(input1, input2, output));
            }
            break;
        }
        case OperationType::OR:
        {
            auto& input1 = wires.getWireRef(wiresFromInstruction.getWires()[0]);
            auto& input2 = wires.getWireRef(wiresFromInstruction.getWires()[1]);
            auto& output = wires.getWireRef(wiresFromInstruction.getWires()[2]);
            operations.emplace_back(std::make_unique<Or>(input1, input2, output));
            break;
        }
        case OperationType::LSHIFT:
        {
            auto& input = wires.getWireRef(wiresFromInstruction.getWires()[0]);
            auto& output = wires.getWireRef(wiresFromInstruction.getWires()[1]);
            const auto number = getSignalFromInstruction (instruction);
            operations.emplace_back(std::make_unique<LShift>(input, number, output));
            break;
        }
        case OperationType::RSHIFT:
        {
            auto& input = wires.getWireRef(wiresFromInstruction.getWires()[0]);
            auto& output = wires.getWireRef(wiresFromInstruction.getWires()[1]);
            const auto number = getSignalFromInstruction (instruction);
            operations.emplace_back(std::make_unique<RShift>(input, number, output));
            break;
        }
        case OperationType::NOT:
        {
            auto& input = wires.getWireRef(wiresFromInstruction.getWires()[0]);
            auto& output = wires.getWireRef(wiresFromInstruction.getWires()[1]);
            operations.emplace_back(std::make_unique<Not>(input, output));
            break;
        }
        case OperationType::ATTRIBUTION:
        {
            if(std::isdigit(instruction.front()))
            {
                const auto input = getSignalFromInstruction (instruction);
                auto& output = wires.getWireRef(wiresFromInstruction.getWires()[0]);
                operations.emplace_back(std::make_unique<Attribution>(input, output));
            }
            else
            {
                auto& input = wires.getWireRef(wiresFromInstruction.getWires()[0]);
                auto& output = wires.getWireRef(wiresFromInstruction.getWires()[1]);
                operations.emplace_back(std::make_unique<Attribution>(input, output));
            }
            break;
        }
        }
    }

    void run()
    {
        while (std::any_of(std::begin(operations), std::end(operations), [](const auto& operation)
        {
            return !operation->isExecuted();
        }))
        {
            for(auto& operation : operations)
            {
                if(!operation->isExecuted() && operation->canBeExecuted())
                {
                    operation->execute();
                }
            }
        }
    }

private:
    std::vector <std::unique_ptr<Operation>> operations;
};

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    Wires wires;
    Operations operations;

    foreachLineIn(fileContent, [&wires](const std::string& line)
    {
        const auto operationType = getOperationFromInstruction (line);
        auto& wiresFromInstruction = getWiresNameInInstruction (line);
        for(auto& w : wiresFromInstruction.getWires())
        {
            wires.addNewWire(w);
        }
    });

    foreachLineIn(fileContent, [&wires, &operations](const std::string& line)
    {
        const auto operationType = getOperationFromInstruction (line);
        auto& wiresFromInstruction = getWiresNameInInstruction (line);
        operations.addNewOperation(operationType, wires, wiresFromInstruction, line);
    });

   operations.run();

    auto& wiresList = wires.getWires();
    const auto wire = std::find_if(std::begin(wiresList), std::end(wiresList), [](const auto wire)
    {
        return wire.getName() == "a";
    });

    assert(wire != std::end(wiresList));

    if(expectedResult == wire->getSignal())
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << wire->getSignal() << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
