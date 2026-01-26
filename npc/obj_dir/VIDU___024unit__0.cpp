// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VIDU.h for the primary calling header

#include "VIDU__pch.h"

extern "C" int pmem_read(int raddr);

void VIDU___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VIDU___024unit____Vdpiimwrap_pmem_read_TOP____024unit\n"); );
    // Body
    int raddr__Vcvt;
    raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = (pmem_read__Vfuncrtn__Vcvt);
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

void VIDU___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VIDU___024unit____Vdpiimwrap_pmem_write_TOP____024unit\n"); );
    // Body
    int waddr__Vcvt;
    waddr__Vcvt = waddr;
    int wdata__Vcvt;
    wdata__Vcvt = wdata;
    char wmask__Vcvt;
    wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

extern "C" void break_test(svLogic is_ebreak);

void VIDU___024unit____Vdpiimwrap_break_test_TOP____024unit(CData/*0:0*/ is_ebreak) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VIDU___024unit____Vdpiimwrap_break_test_TOP____024unit\n"); );
    // Body
    svLogic is_ebreak__Vcvt;
    is_ebreak__Vcvt = is_ebreak;
    break_test(is_ebreak__Vcvt);
}

extern "C" void inst_get(int inst);

void VIDU___024unit____Vdpiimwrap_inst_get_TOP____024unit(IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VIDU___024unit____Vdpiimwrap_inst_get_TOP____024unit\n"); );
    // Body
    int inst__Vcvt;
    inst__Vcvt = inst;
    inst_get(inst__Vcvt);
}
