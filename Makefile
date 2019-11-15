
format:
	set -f
	find . \( -name '*.cmake' -o -name 'CMakeLists.txt' \) -exec cmake-format -i {} \;
	set +f
