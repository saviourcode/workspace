CXX = gcc
CXXFLAGS = -Wall -o

SRC_DIR = ./src
BIN_DIR = ./bin

TARGET_SRCS = $(wildcard $(SRC_DIR)/*.c)
TARGET_TEMP = $(foreach target_src, $(TARGET_SRCS), $(subst $(SRC_DIR), $(BIN_DIR), $(target_src)))
TARGET = $(TARGET_TEMP:.c=.out)

all: $(TARGET)
	@echo "Seat back, Project is starting now ..."
	@mkdir -p "dir1"
	@mkdir -p "dir2"
	@echo -e "This is file1 present in dir1\nChild process1 will soon transfer me." > ./dir1/file1
	@echo -e "I am another file from dir1\nChild process1 will soon transfer me." > ./dir1/file2
	@echo -e "This is file3 present in dir2\nChild process2 will soon transfer me." > ./dir2/file3
	@echo -e "I am another file from dir2\nChild process2 will soon transfer me." > ./dir2/file4
	@$(TARGET)
	@echo -e "Project Completed Successfully! Please do \"make clean\" before running again"

$(TARGET): $(BIN_DIR)/%.out: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $@ $<
	@echo "Build Successful!"

clean:
	rm -rf $(BIN_DIR)
	rm -rf "dir1"
	rm -rf "dir2"



