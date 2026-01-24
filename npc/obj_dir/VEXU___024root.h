// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VEXU.h for the primary calling header

#ifndef VERILATED_VEXU___024ROOT_H_
#define VERILATED_VEXU___024ROOT_H_  // guard

#include "verilated.h"


class VEXU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VEXU___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*4:0*/ top__DOT__raddr1;
    CData/*4:0*/ top__DOT__raddr2;
    CData/*0:0*/ top__DOT__my_EXU__DOT__is_jalr_ok;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    VL_IN(inst,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ top__DOT__my_EXU__DOT__ALU_result;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__GPR__DOT__rf;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VEXU__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VEXU___024root(VEXU__Syms* symsp, const char* namep);
    ~VEXU___024root();
    VL_UNCOPYABLE(VEXU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
