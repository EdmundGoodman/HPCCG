TARGET = test_HPCCG
TEST_TARGET = Catch2Tests
CMAKE_BUILD_DIR = build

.PHONY: all
all: clean $(TARGET)

$(CMAKE_BUILD_DIR):
	cmake -S . -B build

$(TARGET): $(CMAKE_BUILD_DIR)
	cmake --build $(CMAKE_BUILD_DIR) --target $(TARGET)

.PHONY: test
test: $(CMAKE_BUILD_DIR)
	cmake --build $(CMAKE_BUILD_DIR) --target $(TEST_TARGET) -j 6
	./$(CMAKE_BUILD_DIR)/test/$(TEST_TARGET)

.PHONY: clean
clean:
	@rm -rf $(TARGET) $(CMAKE_BUILD_DIR)

.PHONY: no_yaml
no_yaml:
	@rm -f *.yaml

.PHONY: format
format:
	@clang-format -style=file -i src/*.cpp src/*.hpp
