
format:
	set -f
	find . -name '*.cmake' -or -name 'CMakeLists.txt' -exec cmake-format -i {} \;
	set +f
