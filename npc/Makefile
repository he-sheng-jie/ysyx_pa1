# Makefile for Verilator projects
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --trace --cc --exe --build -j 0

# 设计文件
VERILOG_SOURCES = ./vsrc/top.v
CPP_SOURCES = ./csrc/main.cpp

# 默认目标
all: sim

# 运行Verilator
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	./setup.sh
	$(VERILATOR) $(VERILATOR_FLAGS) $(CPP_SOURCES) $(VERILOG_SOURCES)

# 运行仿真
run: simulate
	./obj_dir/Vtop

# 清理生成的文件
clean:
	rm -rf obj_dir
	rm -f *.vcd

# 语法检查
lint:
	$(VERILATOR) --lint-only $(VERILOG_SOURCES)

.PHONY: all simulate run clean lint
include ../Makefile
