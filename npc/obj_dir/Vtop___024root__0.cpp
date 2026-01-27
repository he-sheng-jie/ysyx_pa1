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

void Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, CData/*7:0*/ rmask, IData/*31:0*/ &pmem_read__Vfuncrtn);

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
                                                    ((((IData)(vlSelfRef.rst) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__top__DOT__GPR__DOT__rf__v0;
    __VdlyVal__top__DOT__GPR__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__GPR__DOT__rf__v0;
    __VdlyDim0__top__DOT__GPR__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__GPR__DOT__rf__v0;
    __VdlySet__top__DOT__GPR__DOT__rf__v0 = 0;
    // Body
    if ((0x23U == (0x0000007fU & vlSelfRef.inst))) {
        Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr, vlSelfRef.top__DOT__my_CU__DOT__rdata2, 
                                                               ((0U 
                                                                 == 
                                                                 (7U 
                                                                  & (vlSelfRef.inst 
                                                                     >> 0x0000000cU)))
                                                                 ? 
                                                                ((2U 
                                                                  & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                                                  ? 
                                                                 ((1U 
                                                                   & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                                                   ? 8U
                                                                   : 4U)
                                                                  : 
                                                                 ((1U 
                                                                   & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                                                   ? 2U
                                                                   : 1U))
                                                                 : 
                                                                ((2U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlSelfRef.inst 
                                                                      >> 0x0000000cU)))
                                                                  ? 0xffU
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (7U 
                                                                    & (vlSelfRef.inst 
                                                                       >> 0x0000000cU)))
                                                                   ? 
                                                                  ((2U 
                                                                    & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                                                    ? 0x0cU
                                                                    : 3U)
                                                                   : 0U))));
    }
    __VdlySet__top__DOT__GPR__DOT__rf__v0 = 0U;
    if (((0x37U == (0x0000007fU & vlSelfRef.inst)) 
         | ((0x17U == (0x0000007fU & vlSelfRef.inst)) 
            | ((3U == (0x0000007fU & vlSelfRef.inst)) 
               | ((0x6fU == (0x0000007fU & vlSelfRef.inst)) 
                  | ((0x33U == (0x0000007fU & vlSelfRef.inst)) 
                     | ((0x13U == (0x0000007fU & vlSelfRef.inst)) 
                        | (IData)(vlSelfRef.top__DOT__my_CU__DOT__is_jalr)))))))) {
        __VdlyVal__top__DOT__GPR__DOT__rf__v0 = vlSelfRef.top__DOT__my_CU__DOT__wdata;
        __VdlyDim0__top__DOT__GPR__DOT__rf__v0 = (0x0000001fU 
                                                  & (vlSelfRef.inst 
                                                     >> 7U));
        __VdlySet__top__DOT__GPR__DOT__rf__v0 = 1U;
    }
    if (__VdlySet__top__DOT__GPR__DOT__rf__v0) {
        vlSelfRef.top__DOT__GPR__DOT__rf[__VdlyDim0__top__DOT__GPR__DOT__rf__v0] 
            = __VdlyVal__top__DOT__GPR__DOT__rf__v0;
    }
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
    vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2 
        = ((0x13U == (0x0000007fU & vlSelfRef.inst))
            ? vlSelfRef.top__DOT__my_CU__DOT__imm_i
            : vlSelfRef.top__DOT__my_CU__DOT__rdata2);
    vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr 
        = ((((- (IData)((vlSelfRef.inst >> 0x0000001fU))) 
             << 0x0000000cU) | ((0x00000fe0U & (vlSelfRef.inst 
                                                >> 0x00000014U)) 
                                | (0x0000001fU & (vlSelfRef.inst 
                                                  >> 7U)))) 
           + vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1);
    vlSelfRef.top__DOT__mem_to_reg_addr = (vlSelfRef.top__DOT__my_CU__DOT__imm_i 
                                           + vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                                == vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2);
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
}

void Vtop___024unit____Vdpiimwrap_break_test_TOP____024unit(CData/*0:0*/ is_ebreak);

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__pc_before_reg = ((IData)(vlSelfRef.rst)
                                          ? 0U : vlSelfRef.pc);
    vlSelfRef.pc_before = vlSelfRef.top__DOT__pc_before_reg;
    if (vlSelfRef.rst) {
        vlSelfRef.pc = 0x80000000U;
    } else {
        Vtop___024unit____Vdpiimwrap_break_test_TOP____024unit(
                                                               (0x00100073U 
                                                                == vlSelfRef.inst));
        vlSelfRef.pc = vlSelfRef.top__DOT__my_CU__DOT__pc_next;
    }
    vlSelfRef.debug_rf[0x00000020U] = vlSelfRef.pc;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
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
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
