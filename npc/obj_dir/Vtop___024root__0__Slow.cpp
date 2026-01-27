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
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
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
    vlSelfRef.top__DOT__GPR__DOT__rf[0U] = 0U;
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

void Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, CData/*7:0*/ rmask, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc_before = vlSelfRef.top__DOT__pc_before_reg;
    vlSelfRef.debug_rf[0x00000020U] = vlSelfRef.pc;
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[1U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[1U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[2U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[2U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[3U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[3U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[4U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[4U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[5U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[5U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[6U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[6U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[7U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[7U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[8U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[8U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[9U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[9U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000000aU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000000aU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000000bU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000000bU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000000cU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000000cU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000000dU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000000dU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000000eU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000000eU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000000fU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000000fU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000010U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000010U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000011U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000011U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000012U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000012U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000013U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000013U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000014U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000014U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000015U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000015U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000016U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000016U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000017U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000017U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000018U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000018U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x00000019U] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x00000019U];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000001aU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000001aU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000001bU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000001bU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000001cU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000001cU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000001dU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000001dU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000001eU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000001eU];
    vlSelfRef.top__DOT____Vcellout__GPR__debug_rf[0x0000001fU] 
        = vlSelfRef.top__DOT__GPR__DOT__rf[0x0000001fU];
    vlSelfRef.top__DOT__my_CU__DOT__is_jalr = (IData)(
                                                      (0x00000067U 
                                                       == 
                                                       (0x0000707fU 
                                                        & vlSelfRef.inst)));
    vlSelfRef.top__DOT__my_CU__DOT__rdata2 = ((0U == 
                                               (0x0000001fU 
                                                & (vlSelfRef.inst 
                                                   >> 0x00000014U)))
                                               ? 0U
                                               : vlSelfRef.top__DOT__GPR__DOT__rf
                                              [(0x0000001fU 
                                                & (vlSelfRef.inst 
                                                   >> 0x00000014U))]);
    vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
        = ((0U == (0x0000001fU & (vlSelfRef.inst >> 0x0000000fU)))
            ? 0U : vlSelfRef.top__DOT__GPR__DOT__rf
           [(0x0000001fU & (vlSelfRef.inst >> 0x0000000fU))]);
    vlSelfRef.top__DOT__my_CU__DOT__imm_i = (((- (IData)(
                                                         (vlSelfRef.inst 
                                                          >> 0x0000001fU))) 
                                              << 0x0000000cU) 
                                             | (vlSelfRef.inst 
                                                >> 0x00000014U));
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[1U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [1U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[2U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [2U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[3U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [3U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[4U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [4U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[5U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [5U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[6U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [6U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[7U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [7U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[8U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [8U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[9U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [9U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000000aU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000aU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000000bU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000bU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000000cU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000cU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000000dU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000dU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000000eU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000eU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000000fU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000fU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000010U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000010U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000011U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000011U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000012U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000012U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000013U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000013U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000014U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000014U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000015U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000015U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000016U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000016U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000017U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000017U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000018U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000018U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x00000019U] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000019U];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000001aU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001aU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000001bU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001bU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000001cU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001cU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000001dU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001dU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000001eU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001eU];
    vlSelfRef.top__DOT__GPR__DOT__debug_rf[0x0000001fU] 
        = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001fU];
    vlSelfRef.debug_rf[0U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0U];
    vlSelfRef.debug_rf[1U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [1U];
    vlSelfRef.debug_rf[2U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [2U];
    vlSelfRef.debug_rf[3U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [3U];
    vlSelfRef.debug_rf[4U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [4U];
    vlSelfRef.debug_rf[5U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [5U];
    vlSelfRef.debug_rf[6U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [6U];
    vlSelfRef.debug_rf[7U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [7U];
    vlSelfRef.debug_rf[8U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [8U];
    vlSelfRef.debug_rf[9U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [9U];
    vlSelfRef.debug_rf[0x0000000aU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000aU];
    vlSelfRef.debug_rf[0x0000000bU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000bU];
    vlSelfRef.debug_rf[0x0000000cU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000cU];
    vlSelfRef.debug_rf[0x0000000dU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000dU];
    vlSelfRef.debug_rf[0x0000000eU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000eU];
    vlSelfRef.debug_rf[0x0000000fU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000000fU];
    vlSelfRef.debug_rf[0x00000010U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000010U];
    vlSelfRef.debug_rf[0x00000011U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000011U];
    vlSelfRef.debug_rf[0x00000012U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000012U];
    vlSelfRef.debug_rf[0x00000013U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000013U];
    vlSelfRef.debug_rf[0x00000014U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000014U];
    vlSelfRef.debug_rf[0x00000015U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000015U];
    vlSelfRef.debug_rf[0x00000016U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000016U];
    vlSelfRef.debug_rf[0x00000017U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000017U];
    vlSelfRef.debug_rf[0x00000018U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000018U];
    vlSelfRef.debug_rf[0x00000019U] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x00000019U];
    vlSelfRef.debug_rf[0x0000001aU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001aU];
    vlSelfRef.debug_rf[0x0000001bU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001bU];
    vlSelfRef.debug_rf[0x0000001cU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001cU];
    vlSelfRef.debug_rf[0x0000001dU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001dU];
    vlSelfRef.debug_rf[0x0000001eU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001eU];
    vlSelfRef.debug_rf[0x0000001fU] = vlSelfRef.top__DOT____Vcellout__GPR__debug_rf
        [0x0000001fU];
    vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr 
        = ((((- (IData)((vlSelfRef.inst >> 0x0000001fU))) 
             << 0x0000000cU) | ((0x00000fe0U & (vlSelfRef.inst 
                                                >> 0x00000014U)) 
                                | (0x0000001fU & (vlSelfRef.inst 
                                                  >> 7U)))) 
           + vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1);
    vlSelfRef.top__DOT__my_CU__DOT__alu_op = 0U;
    if ((0x33U == (0x0000007fU & vlSelfRef.inst))) {
        vlSelfRef.top__DOT__my_CU__DOT__alu_op = ((0x40000000U 
                                                   & vlSelfRef.inst)
                                                   ? 
                                                  ((0x00004000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((0x00002000U 
                                                     & vlSelfRef.inst)
                                                     ? 0U
                                                     : 
                                                    ((0x00001000U 
                                                      & vlSelfRef.inst)
                                                      ? 7U
                                                      : 0U))
                                                    : 
                                                   ((0x00002000U 
                                                     & vlSelfRef.inst)
                                                     ? 0U
                                                     : 
                                                    ((0x00001000U 
                                                      & vlSelfRef.inst)
                                                      ? 0U
                                                      : 1U)))
                                                   : 
                                                  ((0x00004000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((0x00002000U 
                                                     & vlSelfRef.inst)
                                                     ? 
                                                    ((0x00001000U 
                                                      & vlSelfRef.inst)
                                                      ? 2U
                                                      : 3U)
                                                     : 
                                                    ((0x00001000U 
                                                      & vlSelfRef.inst)
                                                      ? 6U
                                                      : 4U))
                                                    : 
                                                   ((0x00002000U 
                                                     & vlSelfRef.inst)
                                                     ? 
                                                    ((0x00001000U 
                                                      & vlSelfRef.inst)
                                                      ? 0x0aU
                                                      : 8U)
                                                     : 
                                                    ((0x00001000U 
                                                      & vlSelfRef.inst)
                                                      ? 5U
                                                      : 0U))));
    } else if ((0x13U == (0x0000007fU & vlSelfRef.inst))) {
        vlSelfRef.top__DOT__my_CU__DOT__alu_op = ((0x00004000U 
                                                   & vlSelfRef.inst)
                                                   ? 
                                                  ((0x00002000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((0x00001000U 
                                                     & vlSelfRef.inst)
                                                     ? 2U
                                                     : 3U)
                                                    : 
                                                   ((0x00001000U 
                                                     & vlSelfRef.inst)
                                                     ? 
                                                    ((0x00000400U 
                                                      & vlSelfRef.top__DOT__my_CU__DOT__imm_i)
                                                      ? 7U
                                                      : 6U)
                                                     : 4U))
                                                   : 
                                                  ((0x00002000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((0x00001000U 
                                                     & vlSelfRef.inst)
                                                     ? 0x0aU
                                                     : 8U)
                                                    : 
                                                   ((0x00001000U 
                                                     & vlSelfRef.inst)
                                                     ? 5U
                                                     : 0U)));
    }
    vlSelfRef.top__DOT__mem_to_reg_addr = (vlSelfRef.top__DOT__my_CU__DOT__imm_i 
                                           + vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1);
    vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2 
        = ((0x13U == (0x0000007fU & vlSelfRef.inst))
            ? vlSelfRef.top__DOT__my_CU__DOT__imm_i
            : vlSelfRef.top__DOT__my_CU__DOT__rdata2);
    vlSelfRef.top__DOT__my_CU__DOT__pc_next = ((0x6fU 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.inst))
                                                ? (
                                                   ((((0x00000ffeU 
                                                       & ((- (IData)(
                                                                     (vlSelfRef.inst 
                                                                      >> 0x0000001fU))) 
                                                          << 1U)) 
                                                      | (vlSelfRef.inst 
                                                         >> 0x0000001fU)) 
                                                     << 0x00000014U) 
                                                    | ((((0x000001feU 
                                                          & (vlSelfRef.inst 
                                                             >> 0x0000000bU)) 
                                                         | (1U 
                                                            & (vlSelfRef.inst 
                                                               >> 0x00000014U))) 
                                                        << 0x0000000bU) 
                                                       | (0x000007feU 
                                                          & (vlSelfRef.inst 
                                                             >> 0x00000014U)))) 
                                                   + vlSelfRef.pc)
                                                : ((IData)(vlSelfRef.top__DOT__my_CU__DOT__is_jalr)
                                                    ? 
                                                   (0xfffffffeU 
                                                    & vlSelfRef.top__DOT__mem_to_reg_addr)
                                                    : 
                                                   (((0x63U 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSelfRef.inst)) 
                                                     & ((IData)(
                                                                ((0U 
                                                                  == 
                                                                  (0x00007000U 
                                                                   & vlSelfRef.inst)) 
                                                                 & (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                                                    == vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                                        | ((IData)(
                                                                   ((0x00001000U 
                                                                     == 
                                                                     (0x00007000U 
                                                                      & vlSelfRef.inst)) 
                                                                    & (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                                                       != vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                                           | ((IData)(
                                                                      ((0x00004000U 
                                                                        == 
                                                                        (0x00007000U 
                                                                         & vlSelfRef.inst)) 
                                                                       & VL_LTS_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                                              | ((IData)(
                                                                         ((0x00005000U 
                                                                           == 
                                                                           (0x00007000U 
                                                                            & vlSelfRef.inst)) 
                                                                          & VL_GTES_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                                                 | ((IData)(
                                                                            ((0x00006000U 
                                                                              == 
                                                                              (0x00007000U 
                                                                               & vlSelfRef.inst)) 
                                                                             & (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                                                                < vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                                                    | (IData)(
                                                                              ((0x00007000U 
                                                                                == 
                                                                                (0x00007000U 
                                                                                & vlSelfRef.inst)) 
                                                                               & (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                                                                >= vlSelfRef.top__DOT__my_CU__DOT__rdata2)))))))))
                                                     ? 
                                                    ((((- (IData)(
                                                                  (vlSelfRef.inst 
                                                                   >> 0x0000001fU))) 
                                                       << 0x0000000cU) 
                                                      | ((0x00000800U 
                                                          & (vlSelfRef.inst 
                                                             << 4U)) 
                                                         | ((0x000007e0U 
                                                             & (vlSelfRef.inst 
                                                                >> 0x00000014U)) 
                                                            | (0x0000001eU 
                                                               & (vlSelfRef.inst 
                                                                  >> 7U))))) 
                                                     + vlSelfRef.pc)
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.pc))));
    vlSelfRef.top__DOT__mem_read_data = ((3U == (0x0000007fU 
                                                 & vlSelfRef.inst))
                                          ? ([&]() {
                Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.top__DOT__mem_to_reg_addr, 
                                                                      ((0x00004000U 
                                                                        & vlSelfRef.inst)
                                                                        ? 
                                                                       ((0x00002000U 
                                                                         & vlSelfRef.inst)
                                                                         ? 0U
                                                                         : 
                                                                        ((0x00001000U 
                                                                          & vlSelfRef.inst)
                                                                          ? 2U
                                                                          : 1U))
                                                                        : 
                                                                       ((0x00002000U 
                                                                         & vlSelfRef.inst)
                                                                         ? 
                                                                        ((0x00001000U 
                                                                          & vlSelfRef.inst)
                                                                          ? 0U
                                                                          : 0xffU)
                                                                         : 
                                                                        ((0x00001000U 
                                                                          & vlSelfRef.inst)
                                                                          ? 2U
                                                                          : 1U))), vlSelfRef.__Vfunc_pmem_read__0__Vfuncout);
            }(), vlSelfRef.__Vfunc_pmem_read__0__Vfuncout)
                                          : 0U);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                                == vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2);
    vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__alu_result 
        = ((8U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
            ? ((4U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                ? ((2U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? VL_DIV_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                        : (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           * vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2))
                    : ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                            ? 0U : 1U) : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                                           ? 1U : 0U)))
                : ((2U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? ((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                            >= vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                            ? 1U : 0U) : ((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                           < vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                                           ? 1U : 0U))
                    : ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? (VL_GTES_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                            ? 1U : 0U) : (VL_LTS_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                                           ? 1U : 0U))))
            : ((4U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                ? ((2U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? VL_SHIFTRS_III(32,32,32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, 
                                         (0x0000001fU 
                                          & vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2))
                        : VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, 
                                        (0x0000001fU 
                                         & vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)))
                    : ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? VL_SHIFTL_III(32,32,32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, 
                                        (0x0000001fU 
                                         & vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2))
                        : (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           ^ vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)))
                : ((2U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           | vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                        : (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           & vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2))
                    : ((1U & (IData)(vlSelfRef.top__DOT__my_CU__DOT__alu_op))
                        ? (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           - vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)
                        : (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           + vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2)))));
    vlSelfRef.top__DOT__my_CU__DOT__wdata = ((3U == 
                                              (0x0000007fU 
                                               & vlSelfRef.inst))
                                              ? ((0x00004000U 
                                                  & vlSelfRef.inst)
                                                  ? 
                                                 ((0x00002000U 
                                                   & vlSelfRef.inst)
                                                   ? 0U
                                                   : 
                                                  ((0x00001000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   (0x0000ffffU 
                                                    & vlSelfRef.top__DOT__mem_read_data)
                                                    : 
                                                   (0x000000ffU 
                                                    & vlSelfRef.top__DOT__mem_read_data)))
                                                  : 
                                                 ((0x00002000U 
                                                   & vlSelfRef.inst)
                                                   ? 
                                                  ((0x00001000U 
                                                    & vlSelfRef.inst)
                                                    ? 0U
                                                    : vlSelfRef.top__DOT__mem_read_data)
                                                   : 
                                                  ((0x00001000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.top__DOT__mem_read_data 
                                                                    >> 0x0fU)))) 
                                                     << 0x00000010U) 
                                                    | (0x0000ffffU 
                                                       & vlSelfRef.top__DOT__mem_read_data))
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.top__DOT__mem_read_data 
                                                                    >> 7U)))) 
                                                     << 8U) 
                                                    | (0x000000ffU 
                                                       & vlSelfRef.top__DOT__mem_read_data)))))
                                              : ((0x37U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.inst))
                                                  ? 
                                                 (0xfffff000U 
                                                  & vlSelfRef.inst)
                                                  : 
                                                 ((0x17U 
                                                   == 
                                                   (0x0000007fU 
                                                    & vlSelfRef.inst))
                                                   ? 
                                                  ((0xfffff000U 
                                                    & vlSelfRef.inst) 
                                                   + vlSelfRef.pc)
                                                   : 
                                                  (((0x13U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.inst)) 
                                                    | (0x33U 
                                                       == 
                                                       (0x0000007fU 
                                                        & vlSelfRef.inst)))
                                                    ? vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__alu_result
                                                    : 
                                                   (((0x6fU 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSelfRef.inst)) 
                                                     | (IData)(vlSelfRef.top__DOT__my_CU__DOT__is_jalr))
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.pc)
                                                     : 0U)))));
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
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
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
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->pc_before = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10504099417225522876ull);
    vlSelf->num = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18387576601196128811ull);
    for (int __Vi0 = 0; __Vi0 < 33; ++__Vi0) {
        vlSelf->debug_rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17395848816745678792ull);
    }
    vlSelf->top__DOT__pc_before_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13630982230877739863ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT____Vcellout__GPR__debug_rf[__Vi0] = 0;
    }
    vlSelf->top__DOT__mem_to_reg_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15100006851109256109ull);
    vlSelf->top__DOT__mem_read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15051047848365176992ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__GPR__DOT__debug_rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8430322018413524839ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__GPR__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15517070834399133738ull);
    }
    vlSelf->top__DOT__my_CU__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15665307827884499557ull);
    vlSelf->top__DOT__my_CU__DOT__imm_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14887989624851312399ull);
    vlSelf->top__DOT__my_CU__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1668054295204901997ull);
    vlSelf->top__DOT__my_CU__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13569732812111764129ull);
    vlSelf->top__DOT__my_CU__DOT__reg_to_mem_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9126348976885466880ull);
    vlSelf->top__DOT__my_CU__DOT__is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12167784185181765715ull);
    vlSelf->top__DOT__my_CU__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1338246677905030045ull);
    vlSelf->top__DOT__my_CU__DOT__my_ALU__DOT__num1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14678659406872679087ull);
    vlSelf->top__DOT__my_CU__DOT__my_ALU__DOT__num2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17037612138979761690ull);
    vlSelf->top__DOT__my_CU__DOT__my_ALU__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13099777358542033882ull);
    vlSelf->__Vfunc_pmem_read__0__Vfuncout = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
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
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
