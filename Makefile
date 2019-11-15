
format:
	set -f
	find . \( -name '*.cmake' -o -name 'CMakeLists.txt' \) -exec cmake-format -i {} \;
	find . \( -name '*.hpp' -o -name '*.cpp' \) -exec clang-format -i {} \;
	set +f
