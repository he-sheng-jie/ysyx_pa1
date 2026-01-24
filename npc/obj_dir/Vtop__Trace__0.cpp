// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.top__DOT__is_jalr_ok));
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__is_add_ok));
        bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__is_lw));
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__is_sw));
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__is_sb));
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__is_memtoreg));
        bufp->chgBit(oldp+6,(((IData)(vlSelfRef.top__DOT__is_sb) 
                              | (IData)(vlSelfRef.top__DOT__is_sw))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__pmemdata),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[0]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[1]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[2]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[3]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[4]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[5]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[6]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[7]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[8]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[9]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[10]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[11]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[12]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[13]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[14]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[15]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[16]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[17]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[18]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[19]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[20]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[21]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[22]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[23]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[24]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[25]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[26]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[27]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[28]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[29]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[30]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+40,(vlSelfRef.clk));
    bufp->chgIData(oldp+41,(vlSelfRef.inst),32);
    bufp->chgIData(oldp+42,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+43,(vlSelfRef.out_pc),32);
    bufp->chgCData(oldp+44,(vlSelfRef.num),5);
    bufp->chgIData(oldp+45,(vlSelfRef.result),32);
    bufp->chgIData(oldp+46,(((IData)(4U) + vlSelfRef.pc)),32);
    bufp->chgBit(oldp+47,((0x00100073U == vlSelfRef.inst)));
    bufp->chgBit(oldp+48,(((IData)((0x00000013U == 
                                    (0x0000707fU & vlSelfRef.inst))) 
                           | ((IData)(vlSelfRef.top__DOT__is_jalr_ok) 
                              | ((0x37U == (0x0000007fU 
                                            & vlSelfRef.inst)) 
                                 | ((3U == (0x0000007fU 
                                            & vlSelfRef.inst)) 
                                    | (IData)(vlSelfRef.top__DOT__is_add_ok)))))));
    bufp->chgIData(oldp+49,(((IData)(vlSelfRef.top__DOT__is_memtoreg)
                              ? ((IData)(vlSelfRef.top__DOT__is_lw)
                                  ? vlSelfRef.top__DOT__pmemdata
                                  : ((2U & vlSelfRef.top__DOT__ALU_result)
                                      ? ((1U & vlSelfRef.top__DOT__ALU_result)
                                          ? (0x000000ffU 
                                             & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 0x00000018U))
                                          : (0x000000ffU 
                                             & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 0x00000010U)))
                                      : ((1U & vlSelfRef.top__DOT__ALU_result)
                                          ? (0x000000ffU 
                                             & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 8U))
                                          : (0x000000ffU 
                                             & vlSelfRef.top__DOT__pmemdata))))
                              : ((IData)(vlSelfRef.top__DOT__is_jalr_ok)
                                  ? ((IData)(4U) + vlSelfRef.pc)
                                  : vlSelfRef.top__DOT__ALU_result))),32);
    bufp->chgIData(oldp+50,(((0U == (0x0000001fU & 
                                     (vlSelfRef.inst 
                                      >> 0x0000000fU)))
                              ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                             [(0x0000001fU & (vlSelfRef.inst 
                                              >> 0x0000000fU))])),32);
    bufp->chgCData(oldp+51,((0x0000001fU & (vlSelfRef.inst 
                                            >> 0x0000000fU))),5);
    bufp->chgIData(oldp+52,(((0U == (0x0000001fU & 
                                     (vlSelfRef.inst 
                                      >> 0x00000014U)))
                              ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                             [(0x0000001fU & (vlSelfRef.inst 
                                              >> 0x00000014U))])),32);
    bufp->chgCData(oldp+53,((0x0000001fU & (vlSelfRef.inst 
                                            >> 0x00000014U))),5);
    bufp->chgIData(oldp+54,((((- (IData)((vlSelfRef.inst 
                                          >> 0x0000001fU))) 
                              << 0x0000000cU) | (vlSelfRef.inst 
                                                 >> 0x00000014U))),32);
    bufp->chgIData(oldp+55,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->chgIData(oldp+56,((((- (IData)((vlSelfRef.inst 
                                          >> 0x0000001fU))) 
                              << 0x0000000cU) | ((0x00000fe0U 
                                                  & (vlSelfRef.inst 
                                                     >> 0x00000014U)) 
                                                 | (IData)(vlSelfRef.num)))),32);
    bufp->chgBit(oldp+57,((IData)((0x00000013U == (0x0000707fU 
                                                   & vlSelfRef.inst)))));
    bufp->chgBit(oldp+58,((0x37U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+59,((IData)((0x00004003U == (0x0000707fU 
                                                   & vlSelfRef.inst)))));
    bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__ALU_result),32);
    bufp->chgIData(oldp+61,(((IData)(vlSelfRef.top__DOT__is_lw)
                              ? vlSelfRef.top__DOT__pmemdata
                              : ((2U & vlSelfRef.top__DOT__ALU_result)
                                  ? ((1U & vlSelfRef.top__DOT__ALU_result)
                                      ? (0x000000ffU 
                                         & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 0x00000018U))
                                      : (0x000000ffU 
                                         & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 0x00000010U)))
                                  : ((1U & vlSelfRef.top__DOT__ALU_result)
                                      ? (0x000000ffU 
                                         & VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__pmemdata, 8U))
                                      : (0x000000ffU 
                                         & vlSelfRef.top__DOT__pmemdata))))),32);
    bufp->chgCData(oldp+62,(((IData)(vlSelfRef.top__DOT__is_sw)
                              ? 0xffU : ((IData)(vlSelfRef.top__DOT__is_sb)
                                          ? ((2U & vlSelfRef.top__DOT__ALU_result)
                                              ? ((1U 
                                                  & vlSelfRef.top__DOT__ALU_result)
                                                  ? 8U
                                                  : 4U)
                                              : ((1U 
                                                  & vlSelfRef.top__DOT__ALU_result)
                                                  ? 2U
                                                  : 1U))
                                          : 0U))),8);
    bufp->chgIData(oldp+63,(((0x37U == (0x0000007fU 
                                        & vlSelfRef.inst))
                              ? 0U : ((0U == (0x0000001fU 
                                              & (vlSelfRef.inst 
                                                 >> 0x0000000fU)))
                                       ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                      [(0x0000001fU 
                                        & (vlSelfRef.inst 
                                           >> 0x0000000fU))]))),32);
    bufp->chgIData(oldp+64,(((IData)(vlSelfRef.top__DOT__is_add_ok)
                              ? ((0U == (0x0000001fU 
                                         & (vlSelfRef.inst 
                                            >> 0x00000014U)))
                                  ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.inst 
                                                  >> 0x00000014U))])
                              : (((IData)(vlSelfRef.top__DOT__is_sb) 
                                  | (IData)(vlSelfRef.top__DOT__is_sw))
                                  ? (((- (IData)((vlSelfRef.inst 
                                                  >> 0x0000001fU))) 
                                      << 0x0000000cU) 
                                     | ((0x00000fe0U 
                                         & (vlSelfRef.inst 
                                            >> 0x00000014U)) 
                                        | (IData)(vlSelfRef.num)))
                                  : ((0x37U == (0x0000007fU 
                                                & vlSelfRef.inst))
                                      ? (0xfffff000U 
                                         & vlSelfRef.inst)
                                      : (((- (IData)(
                                                     (vlSelfRef.inst 
                                                      >> 0x0000001fU))) 
                                          << 0x0000000cU) 
                                         | (vlSelfRef.inst 
                                            >> 0x00000014U)))))),32);
    bufp->chgIData(oldp+65,((((IData)(vlSelfRef.top__DOT__is_sb) 
                              | (IData)(vlSelfRef.top__DOT__is_sw))
                              ? (((- (IData)((vlSelfRef.inst 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000fe0U & (vlSelfRef.inst 
                                                  >> 0x00000014U)) 
                                  | (IData)(vlSelfRef.num)))
                              : ((0x37U == (0x0000007fU 
                                            & vlSelfRef.inst))
                                  ? (0xfffff000U & vlSelfRef.inst)
                                  : (((- (IData)((vlSelfRef.inst 
                                                  >> 0x0000001fU))) 
                                      << 0x0000000cU) 
                                     | (vlSelfRef.inst 
                                        >> 0x00000014U))))),32);
    bufp->chgCData(oldp+66,((0x0000007fU & vlSelfRef.inst)),7);
    bufp->chgCData(oldp+67,((7U & (vlSelfRef.inst >> 0x0000000cU))),3);
    bufp->chgCData(oldp+68,((vlSelfRef.inst >> 0x00000019U)),7);
    bufp->chgBit(oldp+69,((0x13U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+70,((0x67U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+71,((0x33U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+72,((3U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+73,((0x23U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+74,((0U == (7U & (vlSelfRef.inst 
                                        >> 0x0000000cU)))));
    bufp->chgBit(oldp+75,((2U == (7U & (vlSelfRef.inst 
                                        >> 0x0000000cU)))));
    bufp->chgBit(oldp+76,((4U == (7U & (vlSelfRef.inst 
                                        >> 0x0000000cU)))));
    bufp->chgBit(oldp+77,((0U == (vlSelfRef.inst >> 0x00000019U))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
