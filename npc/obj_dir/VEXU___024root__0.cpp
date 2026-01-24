// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEXU.h for the primary calling header

#include "VEXU__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VEXU___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VEXU___024root___eval_triggers__ico(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_triggers__ico\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VEXU___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool VEXU___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___trigger_anySet__ico\n"); );
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

void VEXU___024root___ico_sequent__TOP__0(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___ico_sequent__TOP__0\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void VEXU___024root___eval_ico(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_ico\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        VEXU___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool VEXU___024root___eval_phase__ico(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_phase__ico\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    VEXU___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = VEXU___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        VEXU___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VEXU___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VEXU___024root___eval_triggers__act(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_triggers__act\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VEXU___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VEXU___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___trigger_anySet__act\n"); );
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

void VEXU___024root___nba_sequent__TOP__0(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___nba_sequent__TOP__0\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__pc;
    __Vdly__pc = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__GPR__DOT__rf__v1;
    __VdlyVal__top__DOT__GPR__DOT__rf__v1 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__GPR__DOT__rf__v1;
    __VdlyDim0__top__DOT__GPR__DOT__rf__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__GPR__DOT__rf__v1;
    __VdlySet__top__DOT__GPR__DOT__rf__v1 = 0;
    // Body
    __Vdly__pc = vlSelfRef.pc;
    __VdlySet__top__DOT__GPR__DOT__rf__v1 = 0U;
    __Vdly__pc = ((IData)(vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok)
                   ? (0xfffffffeU & vlSelfRef.top__DOT__my_EXU__DOT__ALU_result)
                   : ((IData)(4U) + vlSelfRef.pc));
    if ((((IData)((0x00000013U == (0x0000707fU & vlSelfRef.inst))) 
          | (IData)(vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok)) 
         & (0U != (0x0000001fU & (vlSelfRef.inst >> 7U))))) {
        __VdlyVal__top__DOT__GPR__DOT__rf__v1 = ((IData)(vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok)
                                                  ? 
                                                 ((IData)(4U) 
                                                  + vlSelfRef.pc)
                                                  : vlSelfRef.top__DOT__my_EXU__DOT__ALU_result);
        __VdlyDim0__top__DOT__GPR__DOT__rf__v1 = (0x0000001fU 
                                                  & (vlSelfRef.inst 
                                                     >> 7U));
        __VdlySet__top__DOT__GPR__DOT__rf__v1 = 1U;
    }
    vlSelfRef.pc = __Vdly__pc;
    vlSelfRef.top__DOT__GPR__DOT__rf[0U] = 0U;
    if (__VdlySet__top__DOT__GPR__DOT__rf__v1) {
        vlSelfRef.top__DOT__GPR__DOT__rf[__VdlyDim0__top__DOT__GPR__DOT__rf__v1] 
            = __VdlyVal__top__DOT__GPR__DOT__rf__v1;
    }
    vlSelfRef.result = vlSelfRef.top__DOT__GPR__DOT__rf
        [0x0aU];
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

void VEXU___024root___eval_nba(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_nba\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VEXU___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void VEXU___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VEXU___024root___eval_phase__act(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_phase__act\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VEXU___024root___eval_triggers__act(vlSelf);
    VEXU___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VEXU___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VEXU___024root___eval_phase__nba(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_phase__nba\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VEXU___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VEXU___024root___eval_nba(vlSelf);
        VEXU___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VEXU___024root___eval(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            VEXU___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (VEXU___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VEXU___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VEXU___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VEXU___024root___eval_phase__act(vlSelf));
    } while (VEXU___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VEXU___024root___eval_debug_assertions(VEXU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root___eval_debug_assertions\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
}
#endif  // VL_DEBUG
