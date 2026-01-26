TOPNAME = Vtop
NXDC_FILES = constr/top.nxdc
INC_PATH ?=
NVBOARD_HOME = /home/he/ysyx-workbench/nvboard
VERILATOR = verilator
VERILATOR_FLAGS =  --trace --cc --exe --build -j 0  --top-module top#-Wall#

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

# 设计文件
VERILOG_SOURCES = ./vsrc/*.v
CPP_SOURCES = ./csrc/*.cpp


default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))


# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default


# 运行Verilator
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	./setup.sh
	$(VERILATOR) $(VERILATOR_FLAGS) $(CPP_SOURCES) $(VERILOG_SOURCES)

# 运行仿真
run: $(sim)
	@if [ -z "$(TEST)" ]; then \
		echo "Error: Please specify TEST file, e.g., make run TEST=program.bin"; \
		exit 1; \
	fi
	./obj_dir/Vtop $(TEST)
clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

