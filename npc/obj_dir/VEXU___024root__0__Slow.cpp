// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEXU.h for the primary calling header

#include "VEXU__pch.h"

VL_ATTR_COLD void VEXU___024root___eval_static(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_static\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VEXU___024root___eval_initial__TOP(VEXU___024root* vlSelf);
VL_ATTR_COLD void VEXU___024root____Vm_traceActivitySetAll(VEXU___024root* vlSelf);

VL_ATTR_COLD void VEXU___024root___eval_initial(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_initial\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VEXU___024root___eval_initial__TOP(vlSelf);
    VEXU___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void VEXU___024root___eval_initial__TOP(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_initial__TOP\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = 0U;
    vlSelfRef.top__DOT__GPR__DOT__rf[0U] = 0U;
}

VL_ATTR_COLD void VEXU___024root___eval_final(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_final\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VEXU___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VEXU___024root___eval_phase__stl(VEXU___024root* vlSelf);

VL_ATTR_COLD void VEXU___024root___eval_settle(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_settle\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VEXU___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 1, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (VEXU___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void VEXU___024root___eval_triggers__stl(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_triggers__stl\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VEXU___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool VEXU___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VEXU___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VEXU___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VEXU___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void VEXU___024root___stl_sequent__TOP__0(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___stl_sequent__TOP__0\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.result = vlSelfRef.top__DOT__GPR__DOT__rf
        [0x0aU];
    vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok = (IData)(
                                                          (0x00000067U 
                                                           == 
                                                           (0x0000707fU 
                                                            & vlSelfRef.inst)));
    vlSelfRef.top__DOT__my_EXU__DOT__ALU_result = (
                                                   (((- (IData)(
                                                                (vlSelfRef.inst 
                                                                 >> 0x0000001fU))) 
                                                     << 0x0000000cU) 
                                                    | (vlSelfRef.inst 
                                                       >> 0x00000014U)) 
                                                   + 
                                                   vlSelfRef.top__DOT__GPR__DOT__rf
                                                   [vlSelfRef.top__DOT__raddr1]);
}

VL_ATTR_COLD void VEXU___024root___eval_stl(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_stl\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VEXU___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool VEXU___024root___eval_phase__stl(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_phase__stl\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VEXU___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = VEXU___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VEXU___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VEXU___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VEXU___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(VEXU___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool VEXU___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VEXU___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VEXU___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VEXU___024root____Vm_traceActivitySetAll(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root____Vm_traceActivitySetAll\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void VEXU___024root___ctor_var_reset(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___ctor_var_reset\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9812503827101699671ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16664408842984530663ull);
    vlSelf->top__DOT__raddr1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1789027470327531391ull);
    vlSelf->top__DOT__raddr2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15678664030563911788ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__GPR__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15517070834399133738ull);
    }
    vlSelf->top__DOT__my_EXU__DOT__is_jalr_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1732408022660955799ull);
    vlSelf->top__DOT__my_EXU__DOT__ALU_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 972680090382815341ull);
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
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
