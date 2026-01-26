// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VIDU.h for the primary calling header

#ifndef VERILATED_VIDU___024ROOT_H_
#define VERILATED_VIDU___024ROOT_H_  // guard

#include "verilated.h"
class VIDU___024unit;


class VIDU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VIDU___024root final {
  public:
    // CELLS
    VIDU___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(num,4,0);
    CData/*0:0*/ top__DOT__is_memtoreg;
    CData/*0:0*/ top__DOT__my_IDU__DOT__is_add_ok;
    CData/*0:0*/ top__DOT__my_IDU__DOT__is_jalr_ok;
    CData/*0:0*/ top__DOT__my_IDU__DOT__is_lw;
    CData/*0:0*/ top__DOT__my_IDU__DOT__is_sw;
    CData/*0:0*/ top__DOT__my_IDU__DOT__is_sb;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    VL_IN(inst,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(pc_before,31,0);
    IData/*31:0*/ top__DOT__pc_before_reg;
    IData/*31:0*/ top__DOT__pc_next;
    IData/*31:0*/ top__DOT__ALU_result;
    IData/*31:0*/ top__DOT__pmemdata;
    IData/*31:0*/ __VactIterCount;
    VL_OUT(debug_rf[33],31,0);
    VlUnpacked<IData/*31:0*/, 32> top__DOT____Vcellout__my_WBU__debug_rf;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__my_WBU__DOT__debug_rf;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__my_WBU__DOT__GPR__DOT__debug_rf;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__my_WBU__DOT__GPR__DOT__rf;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VIDU__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VIDU___024root(VIDU__Syms* symsp, const char* namep);
    ~VIDU___024root();
    VL_UNCOPYABLE(VIDU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
