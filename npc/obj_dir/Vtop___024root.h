// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop___024unit;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(num,4,0);
    CData/*0:0*/ top__DOT__my_CU__DOT__is_jalr;
    CData/*3:0*/ top__DOT__my_CU__DOT__alu_op;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    VL_IN(inst,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(pc_before,31,0);
    IData/*31:0*/ top__DOT__pc_before_reg;
    IData/*31:0*/ top__DOT__mem_to_reg_addr;
    IData/*31:0*/ top__DOT__mem_read_data;
    IData/*31:0*/ top__DOT__my_CU__DOT__rdata2;
    IData/*31:0*/ top__DOT__my_CU__DOT__imm_i;
    IData/*31:0*/ top__DOT__my_CU__DOT__wdata;
    IData/*31:0*/ top__DOT__my_CU__DOT__pc_next;
    IData/*31:0*/ top__DOT__my_CU__DOT__reg_to_mem_addr;
    IData/*31:0*/ top__DOT__my_CU__DOT__my_ALU__DOT__num1;
    IData/*31:0*/ top__DOT__my_CU__DOT__my_ALU__DOT__num2;
    IData/*31:0*/ top__DOT__my_CU__DOT__my_ALU__DOT__alu_result;
    IData/*31:0*/ __Vfunc_pmem_read__0__Vfuncout;
    IData/*31:0*/ __VactIterCount;
    VL_OUT(debug_rf[33],31,0);
    VlUnpacked<IData/*31:0*/, 32> top__DOT____Vcellout__GPR__debug_rf;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__GPR__DOT__debug_rf;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__GPR__DOT__rf;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
