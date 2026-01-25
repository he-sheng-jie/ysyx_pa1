// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024unit____Vdpiimwrap_break_test_TOP____024unit(CData/*0:0*/ is_ebreak);

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024unit____Vdpiimwrap_break_test_TOP____024unit(
                                                           (0x00100073U 
                                                            == vlSelfRef.inst));
    vlSelfRef.top__DOT__is_jalr_ok = (IData)((0x00000067U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.inst)));
    vlSelfRef.top__DOT__is_lw = (IData)((0x00002003U 
                                         == (0x0000707fU 
                                             & vlSelfRef.inst)));
    vlSelfRef.num = (0x0000001fU & (vlSelfRef.inst 
                                    >> 7U));
    vlSelfRef.top__DOT__is_add_ok = (IData)((0x00000033U 
                                             == (0xfe00007fU 
                                                 & vlSelfRef.inst)));
    vlSelfRef.top__DOT__is_sw = (IData)((0x00002023U 
                                         == (0x0000707fU 
                                             & vlSelfRef.inst)));
    vlSelfRef.top__DOT__is_sb = (IData)((0x00000023U 
                                         == (0x0000707fU 
                                             & vlSelfRef.inst)));
    vlSelfRef.top__DOT__is_memtoreg = ((IData)((0x00004003U 
                                                == 
                                                (0x0000707fU 
                                                 & vlSelfRef.inst))) 
                                       | (IData)(vlSelfRef.top__DOT__is_lw));
    vlSelfRef.top__DOT__ALU_result = (((0x37U == (0x0000007fU 
                                                  & vlSelfRef.inst))
                                        ? 0U : ((0U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.inst 
                                                     >> 0x0000000fU)))
                                                 ? 0U
                                                 : 
                                                vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                                [(0x0000001fU 
                                                  & (vlSelfRef.inst 
                                                     >> 0x0000000fU))])) 
                                      + ((IData)(vlSelfRef.top__DOT__is_add_ok)
                                          ? ((0U == 
                                              (0x0000001fU 
                                               & (vlSelfRef.inst 
                                                  >> 0x00000014U)))
                                              ? 0U : 
                                             vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                             [(0x0000001fU 
                                               & (vlSelfRef.inst 
                                                  >> 0x00000014U))])
                                          : (((IData)(vlSelfRef.top__DOT__is_sb) 
                                              | (IData)(vlSelfRef.top__DOT__is_sw))
                                              ? (((- (IData)(
                                                             (vlSelfRef.inst 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000fe0U 
                                                     & (vlSelfRef.inst 
                                                        >> 0x00000014U)) 
                                                    | (IData)(vlSelfRef.num)))
                                              : ((0x37U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.inst))
                                                  ? 
                                                 (0xfffff000U 
                                                  & vlSelfRef.inst)
                                                  : 
                                                 (((- (IData)(
                                                              (vlSelfRef.inst 
                                                               >> 0x0000001fU))) 
                                                   << 0x0000000cU) 
                                                  | (vlSelfRef.inst 
                                                     >> 0x00000014U))))));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_pmem_read__1__Vfuncout;
    __Vfunc_pmem_read__1__Vfuncout = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0;
    __VdlyVal__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0;
    __VdlyDim0__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0;
    __VdlySet__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 = 0;
    // Body
    if (((IData)(vlSelfRef.top__DOT__is_sb) | (IData)(vlSelfRef.top__DOT__is_sw))) {
        Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(vlSelfRef.top__DOT__ALU_result, 
                                                               ((0U 
                                                                 == 
                                                                 (0x0000001fU 
                                                                  & (vlSelfRef.inst 
                                                                     >> 0x00000014U)))
                                                                 ? 0U
                                                                 : 
                                                                vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                                                [
                                                                (0x0000001fU 
                                                                 & (vlSelfRef.inst 
                                                                    >> 0x00000014U))]), 
                                                               ((IData)(vlSelfRef.top__DOT__is_sw)
                                                                 ? 0xffU
                                                                 : 
                                                                ((IData)(vlSelfRef.top__DOT__is_sb)
                                                                  ? 
                                                                 ((2U 
                                                                   & vlSelfRef.top__DOT__ALU_result)
                                                                   ? 
                                                                  ((1U 
                                                                    & vlSelfRef.top__DOT__ALU_result)
                                                                    ? 8U
                                                                    : 4U)
                                                                   : 
                                                                  ((1U 
                                                                    & vlSelfRef.top__DOT__ALU_result)
                                                                    ? 2U
                                                                    : 1U))
                                                                  : 0U)));
    }
    __VdlySet__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 = 0U;
    if (vlSelfRef.top__DOT__is_memtoreg) {
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.top__DOT__ALU_result, __Vfunc_pmem_read__1__Vfuncout);
        vlSelfRef.top__DOT__pmemdata = __Vfunc_pmem_read__1__Vfuncout;
    } else {
        vlSelfRef.top__DOT__pmemdata = 0U;
    }
    if (((IData)((0x00000013U == (0x0000707fU & vlSelfRef.inst))) 
         | ((IData)(vlSelfRef.top__DOT__is_jalr_ok) 
            | ((0x37U == (0x0000007fU & vlSelfRef.inst)) 
               | ((3U == (0x0000007fU & vlSelfRef.inst)) 
                  | (IData)(vlSelfRef.top__DOT__is_add_ok)))))) {
        __VdlyVal__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 
            = ((IData)(vlSelfRef.top__DOT__is_memtoreg)
                ? ((IData)(vlSelfRef.top__DOT__is_lw)
                    ? vlSelfRef.top__DOT__pmemdata : 
                   ((2U & vlSelfRef.top__DOT__ALU_result)
                     ? ((1U & vlSelfRef.top__DOT__ALU_result)
                         ? (0x000000ffU & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 0x00000018U))
                         : (0x000000ffU & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 0x00000010U)))
                     : ((1U & vlSelfRef.top__DOT__ALU_result)
                         ? (0x000000ffU & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 8U))
                         : (0x000000ffU & vlSelfRef.top__DOT__pmemdata))))
                : ((IData)(vlSelfRef.top__DOT__is_jalr_ok)
                    ? ((IData)(4U) + vlSelfRef.pc) : vlSelfRef.top__DOT__ALU_result));
        __VdlyDim0__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 
            = vlSelfRef.num;
        __VdlySet__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0 = 1U;
    }
    if (__VdlySet__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0) {
        vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[__VdlyDim0__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0] 
            = __VdlyVal__top__DOT__my_WBU__DOT__GPR__DOT__rf__v0;
    }
    vlSelfRef.debug_rf[0U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000001fU];
    vlSelfRef.debug_rf[1U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000001eU];
    vlSelfRef.debug_rf[2U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000001dU];
    vlSelfRef.debug_rf[3U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000001cU];
    vlSelfRef.debug_rf[4U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000001bU];
    vlSelfRef.debug_rf[5U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000001aU];
    vlSelfRef.debug_rf[6U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000019U];
    vlSelfRef.debug_rf[7U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000018U];
    vlSelfRef.debug_rf[8U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000017U];
    vlSelfRef.debug_rf[9U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000016U];
    vlSelfRef.debug_rf[0x0000000aU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000015U];
    vlSelfRef.debug_rf[0x0000000bU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000014U];
    vlSelfRef.debug_rf[0x0000000cU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000013U];
    vlSelfRef.debug_rf[0x0000000dU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000012U];
    vlSelfRef.debug_rf[0x0000000eU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000011U];
    vlSelfRef.debug_rf[0x0000000fU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x00000010U];
    vlSelfRef.debug_rf[0x00000010U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000000fU];
    vlSelfRef.debug_rf[0x00000011U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000000eU];
    vlSelfRef.debug_rf[0x00000012U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000000dU];
    vlSelfRef.debug_rf[0x00000013U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000000cU];
    vlSelfRef.debug_rf[0x00000014U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000000bU];
    vlSelfRef.debug_rf[0x00000015U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0x0000000aU];
    vlSelfRef.debug_rf[0x00000016U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [9U];
    vlSelfRef.debug_rf[0x00000017U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [8U];
    vlSelfRef.debug_rf[0x00000018U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [7U];
    vlSelfRef.debug_rf[0x00000019U] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [6U];
    vlSelfRef.debug_rf[0x0000001aU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [5U];
    vlSelfRef.debug_rf[0x0000001bU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [4U];
    vlSelfRef.debug_rf[0x0000001cU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [3U];
    vlSelfRef.debug_rf[0x0000001dU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [2U];
    vlSelfRef.debug_rf[0x0000001eU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [1U];
    vlSelfRef.debug_rf[0x0000001fU] = vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
        [0U];
    vlSelfRef.pc = ((IData)(vlSelfRef.top__DOT__is_jalr_ok)
                     ? (0xfffffffcU & vlSelfRef.top__DOT__ALU_result)
                     : vlSelfRef.top__DOT__pc_next);
    vlSelfRef.top__DOT__debug_rf[0U] = vlSelfRef.debug_rf
        [0U];
    vlSelfRef.top__DOT__debug_rf[1U] = vlSelfRef.debug_rf
        [1U];
    vlSelfRef.top__DOT__debug_rf[2U] = vlSelfRef.debug_rf
        [2U];
    vlSelfRef.top__DOT__debug_rf[3U] = vlSelfRef.debug_rf
        [3U];
    vlSelfRef.top__DOT__debug_rf[4U] = vlSelfRef.debug_rf
        [4U];
    vlSelfRef.top__DOT__debug_rf[5U] = vlSelfRef.debug_rf
        [5U];
    vlSelfRef.top__DOT__debug_rf[6U] = vlSelfRef.debug_rf
        [6U];
    vlSelfRef.top__DOT__debug_rf[7U] = vlSelfRef.debug_rf
        [7U];
    vlSelfRef.top__DOT__debug_rf[8U] = vlSelfRef.debug_rf
        [8U];
    vlSelfRef.top__DOT__debug_rf[9U] = vlSelfRef.debug_rf
        [9U];
    vlSelfRef.top__DOT__debug_rf[0x0000000aU] = vlSelfRef.debug_rf
        [0x0000000aU];
    vlSelfRef.top__DOT__debug_rf[0x0000000bU] = vlSelfRef.debug_rf
        [0x0000000bU];
    vlSelfRef.top__DOT__debug_rf[0x0000000cU] = vlSelfRef.debug_rf
        [0x0000000cU];
    vlSelfRef.top__DOT__debug_rf[0x0000000dU] = vlSelfRef.debug_rf
        [0x0000000dU];
    vlSelfRef.top__DOT__debug_rf[0x0000000eU] = vlSelfRef.debug_rf
        [0x0000000eU];
    vlSelfRef.top__DOT__debug_rf[0x0000000fU] = vlSelfRef.debug_rf
        [0x0000000fU];
    vlSelfRef.top__DOT__debug_rf[0x00000010U] = vlSelfRef.debug_rf
        [0x00000010U];
    vlSelfRef.top__DOT__debug_rf[0x00000011U] = vlSelfRef.debug_rf
        [0x00000011U];
    vlSelfRef.top__DOT__debug_rf[0x00000012U] = vlSelfRef.debug_rf
        [0x00000012U];
    vlSelfRef.top__DOT__debug_rf[0x00000013U] = vlSelfRef.debug_rf
        [0x00000013U];
    vlSelfRef.top__DOT__debug_rf[0x00000014U] = vlSelfRef.debug_rf
        [0x00000014U];
    vlSelfRef.top__DOT__debug_rf[0x00000015U] = vlSelfRef.debug_rf
        [0x00000015U];
    vlSelfRef.top__DOT__debug_rf[0x00000016U] = vlSelfRef.debug_rf
        [0x00000016U];
    vlSelfRef.top__DOT__debug_rf[0x00000017U] = vlSelfRef.debug_rf
        [0x00000017U];
    vlSelfRef.top__DOT__debug_rf[0x00000018U] = vlSelfRef.debug_rf
        [0x00000018U];
    vlSelfRef.top__DOT__debug_rf[0x00000019U] = vlSelfRef.debug_rf
        [0x00000019U];
    vlSelfRef.top__DOT__debug_rf[0x0000001aU] = vlSelfRef.debug_rf
        [0x0000001aU];
    vlSelfRef.top__DOT__debug_rf[0x0000001bU] = vlSelfRef.debug_rf
        [0x0000001bU];
    vlSelfRef.top__DOT__debug_rf[0x0000001cU] = vlSelfRef.debug_rf
        [0x0000001cU];
    vlSelfRef.top__DOT__debug_rf[0x0000001dU] = vlSelfRef.debug_rf
        [0x0000001dU];
    vlSelfRef.top__DOT__debug_rf[0x0000001eU] = vlSelfRef.debug_rf
        [0x0000001eU];
    vlSelfRef.top__DOT__debug_rf[0x0000001fU] = vlSelfRef.debug_rf
        [0x0000001fU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0U] = 
        vlSelfRef.debug_rf[0U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[1U] = 
        vlSelfRef.debug_rf[1U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[2U] = 
        vlSelfRef.debug_rf[2U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[3U] = 
        vlSelfRef.debug_rf[3U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[4U] = 
        vlSelfRef.debug_rf[4U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[5U] = 
        vlSelfRef.debug_rf[5U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[6U] = 
        vlSelfRef.debug_rf[6U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[7U] = 
        vlSelfRef.debug_rf[7U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[8U] = 
        vlSelfRef.debug_rf[8U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[9U] = 
        vlSelfRef.debug_rf[9U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000000aU] 
        = vlSelfRef.debug_rf[0x0000000aU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000000bU] 
        = vlSelfRef.debug_rf[0x0000000bU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000000cU] 
        = vlSelfRef.debug_rf[0x0000000cU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000000dU] 
        = vlSelfRef.debug_rf[0x0000000dU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000000eU] 
        = vlSelfRef.debug_rf[0x0000000eU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000000fU] 
        = vlSelfRef.debug_rf[0x0000000fU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000010U] 
        = vlSelfRef.debug_rf[0x00000010U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000011U] 
        = vlSelfRef.debug_rf[0x00000011U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000012U] 
        = vlSelfRef.debug_rf[0x00000012U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000013U] 
        = vlSelfRef.debug_rf[0x00000013U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000014U] 
        = vlSelfRef.debug_rf[0x00000014U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000015U] 
        = vlSelfRef.debug_rf[0x00000015U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000016U] 
        = vlSelfRef.debug_rf[0x00000016U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000017U] 
        = vlSelfRef.debug_rf[0x00000017U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000018U] 
        = vlSelfRef.debug_rf[0x00000018U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x00000019U] 
        = vlSelfRef.debug_rf[0x00000019U];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000001aU] 
        = vlSelfRef.debug_rf[0x0000001aU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000001bU] 
        = vlSelfRef.debug_rf[0x0000001bU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000001cU] 
        = vlSelfRef.debug_rf[0x0000001cU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000001dU] 
        = vlSelfRef.debug_rf[0x0000001dU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000001eU] 
        = vlSelfRef.debug_rf[0x0000001eU];
    vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0x0000001fU] 
        = vlSelfRef.debug_rf[0x0000001fU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0U] 
        = vlSelfRef.debug_rf[0U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[1U] 
        = vlSelfRef.debug_rf[1U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[2U] 
        = vlSelfRef.debug_rf[2U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[3U] 
        = vlSelfRef.debug_rf[3U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[4U] 
        = vlSelfRef.debug_rf[4U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[5U] 
        = vlSelfRef.debug_rf[5U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[6U] 
        = vlSelfRef.debug_rf[6U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[7U] 
        = vlSelfRef.debug_rf[7U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[8U] 
        = vlSelfRef.debug_rf[8U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[9U] 
        = vlSelfRef.debug_rf[9U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000000aU] 
        = vlSelfRef.debug_rf[0x0000000aU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000000bU] 
        = vlSelfRef.debug_rf[0x0000000bU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000000cU] 
        = vlSelfRef.debug_rf[0x0000000cU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000000dU] 
        = vlSelfRef.debug_rf[0x0000000dU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000000eU] 
        = vlSelfRef.debug_rf[0x0000000eU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000000fU] 
        = vlSelfRef.debug_rf[0x0000000fU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000010U] 
        = vlSelfRef.debug_rf[0x00000010U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000011U] 
        = vlSelfRef.debug_rf[0x00000011U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000012U] 
        = vlSelfRef.debug_rf[0x00000012U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000013U] 
        = vlSelfRef.debug_rf[0x00000013U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000014U] 
        = vlSelfRef.debug_rf[0x00000014U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000015U] 
        = vlSelfRef.debug_rf[0x00000015U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000016U] 
        = vlSelfRef.debug_rf[0x00000016U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000017U] 
        = vlSelfRef.debug_rf[0x00000017U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000018U] 
        = vlSelfRef.debug_rf[0x00000018U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x00000019U] 
        = vlSelfRef.debug_rf[0x00000019U];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000001aU] 
        = vlSelfRef.debug_rf[0x0000001aU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000001bU] 
        = vlSelfRef.debug_rf[0x0000001bU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000001cU] 
        = vlSelfRef.debug_rf[0x0000001cU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000001dU] 
        = vlSelfRef.debug_rf[0x0000001dU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000001eU] 
        = vlSelfRef.debug_rf[0x0000001eU];
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0x0000001fU] 
        = vlSelfRef.debug_rf[0x0000001fU];
    vlSelfRef.top__DOT__ALU_result = (((0x37U == (0x0000007fU 
                                                  & vlSelfRef.inst))
                                        ? 0U : ((0U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.inst 
                                                     >> 0x0000000fU)))
                                                 ? 0U
                                                 : 
                                                vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                                [(0x0000001fU 
                                                  & (vlSelfRef.inst 
                                                     >> 0x0000000fU))])) 
                                      + ((IData)(vlSelfRef.top__DOT__is_add_ok)
                                          ? ((0U == 
                                              (0x0000001fU 
                                               & (vlSelfRef.inst 
                                                  >> 0x00000014U)))
                                              ? 0U : 
                                             vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                             [(0x0000001fU 
                                               & (vlSelfRef.inst 
                                                  >> 0x00000014U))])
                                          : (((IData)(vlSelfRef.top__DOT__is_sb) 
                                              | (IData)(vlSelfRef.top__DOT__is_sw))
                                              ? (((- (IData)(
                                                             (vlSelfRef.inst 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000fe0U 
                                                     & (vlSelfRef.inst 
                                                        >> 0x00000014U)) 
                                                    | (IData)(vlSelfRef.num)))
                                              : ((0x37U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.inst))
                                                  ? 
                                                 (0xfffff000U 
                                                  & vlSelfRef.inst)
                                                  : 
                                                 (((- (IData)(
                                                              (vlSelfRef.inst 
                                                               >> 0x0000001fU))) 
                                                   << 0x0000000cU) 
                                                  | (vlSelfRef.inst 
                                                     >> 0x00000014U))))));
    vlSelfRef.top__DOT__pc_next = ((IData)(4U) + vlSelfRef.pc);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 6, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/top.v", 6, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
}
#endif  // VL_DEBUG
