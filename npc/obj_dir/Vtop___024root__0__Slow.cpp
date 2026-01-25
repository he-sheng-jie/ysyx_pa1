// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = 0x80000000U;
    vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[0U] = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 6, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024unit____Vdpiimwrap_break_test_TOP____024unit(
                                                           (0x00100073U 
                                                            == vlSelfRef.inst));
    vlSelfRef.top__DOT__is_jalr_ok = (IData)((0x00000067U 
                                              == (0x0000707fU 
                                                  & vlSelfRef.inst)));
    vlSelfRef.top__DOT__pc_next = ((IData)(4U) + vlSelfRef.pc);
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
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9812503827101699671ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->num = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18387576601196128811ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->debug_rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17395848816745678792ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__debug_rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2843332515537399194ull);
    }
    vlSelf->top__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8995099692902308842ull);
    vlSelf->top__DOT__is_jalr_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12491304843741546873ull);
    vlSelf->top__DOT__is_add_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8777127807608514822ull);
    vlSelf->top__DOT__is_lw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17792527757510442866ull);
    vlSelf->top__DOT__is_sw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7239518796479858432ull);
    vlSelf->top__DOT__is_sb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4655499176252229976ull);
    vlSelf->top__DOT__is_memtoreg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14230434591288044991ull);
    vlSelf->top__DOT__ALU_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 782383008782694384ull);
    vlSelf->top__DOT__pmemdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 521010827019114059ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__my_WBU__DOT__debug_rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5684592570300900533ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17449584412049966226ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__my_WBU__DOT__GPR__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9113849146087864177ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
