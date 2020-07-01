.PHONY: all
all: design run

VERILATOR=verilator
VERILATOR_ROOT ?= $(shell bash -c 'verilator -V|grep VERILATOR_ROOT | head -1 | sed -e "s/^.*=\s*//"')
DESIGN ?= dut
VERILATOR_DEBUB=

VINC := $(VERILATOR_ROOT)/include

obj_dir/V$(DESIGN).cpp: $(DESIGN).sv
	$(VERILATOR) $(VERILATOR_DEBUG) -Wall -cc $(DESIGN).sv

obj_dir/V$(DESIGN)__ALL.a: obj_dir/V$(DESIGN).cpp
	make --no-print-directory -C obj_dir -f V$(DESIGN).mk

design: main.cpp obj_dir/V$(DESIGN)__ALL.a
	g++ -I$(VINC) -I obj_dir            \
		$(VINC)/verilated.cpp       \
		$(VINC)/verilated_vcd_c.cpp \
		main.cpp obj_dir/V$(DESIGN)__ALL.a \
		-o $(DESIGN)
.PHONY: run
run:
	./$(DESIGN) > sim.log
	
.PHONY: clean
clean:
	rm -rf obj_dir/ $(DESIGN) $(DESIGN)trace.vcd sim.log
