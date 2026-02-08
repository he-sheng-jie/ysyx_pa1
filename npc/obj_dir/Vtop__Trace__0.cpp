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
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__my_CU__DOT__imm_i),32);
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__my_CU__DOT__csr_to_reg_en));
        bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__mcycle_write_en));
        bufp->chgBit(oldp+3,(((IData)(vlSelfRef.top__DOT__my_CU__DOT__csr_to_reg_en) 
                              & (0x00000b80U == vlSelfRef.top__DOT__my_CU__DOT__imm_i))));
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__my_CU__DOT__is_jalr));
        bufp->chgCData(oldp+5,(vlSelfRef.top__DOT__my_CU__DOT__alu_op),4);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__my_CU__DOT__rdata2),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__mem_to_reg_addr),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__mem_read_data),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__my_CSR_ALU__DOT__data2),32);
        bufp->chgBit(oldp+12,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                               == vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2),32);
        bufp->chgBit(oldp+14,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                               != vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
        bufp->chgBit(oldp+15,(VL_LTS_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
        bufp->chgBit(oldp+16,(VL_GTES_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
        bufp->chgBit(oldp+17,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                               < vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
        bufp->chgBit(oldp+18,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                               >= vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__alu_result),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[0]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[1]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[2]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[3]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[4]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[5]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[6]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[7]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[8]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[9]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[10]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[11]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[12]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[13]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[14]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[15]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[16]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[17]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[18]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[19]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[20]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[21]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[22]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[23]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[24]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[25]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[26]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[27]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[28]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[29]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[30]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[31]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__GPR__DOT__rf[0]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__GPR__DOT__rf[1]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__GPR__DOT__rf[2]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__GPR__DOT__rf[3]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__GPR__DOT__rf[4]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__GPR__DOT__rf[5]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__GPR__DOT__rf[6]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__GPR__DOT__rf[7]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__GPR__DOT__rf[8]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__GPR__DOT__rf[9]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__GPR__DOT__rf[10]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.top__DOT__GPR__DOT__rf[11]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__GPR__DOT__rf[12]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__GPR__DOT__rf[13]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.top__DOT__GPR__DOT__rf[14]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__GPR__DOT__rf[15]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__GPR__DOT__rf[16]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.top__DOT__GPR__DOT__rf[17]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__GPR__DOT__rf[18]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.top__DOT__GPR__DOT__rf[19]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.top__DOT__GPR__DOT__rf[20]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.top__DOT__GPR__DOT__rf[21]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.top__DOT__GPR__DOT__rf[22]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.top__DOT__GPR__DOT__rf[23]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.top__DOT__GPR__DOT__rf[24]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.top__DOT__GPR__DOT__rf[25]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.top__DOT__GPR__DOT__rf[26]),32);
        bufp->chgIData(oldp+79,(vlSelfRef.top__DOT__GPR__DOT__rf[27]),32);
        bufp->chgIData(oldp+80,(vlSelfRef.top__DOT__GPR__DOT__rf[28]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.top__DOT__GPR__DOT__rf[29]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.top__DOT__GPR__DOT__rf[30]),32);
        bufp->chgIData(oldp+83,(vlSelfRef.top__DOT__GPR__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+84,(vlSelfRef.top__DOT__pc_before_reg),32);
        bufp->chgIData(oldp+85,(vlSelfRef.top__DOT__mcycle),32);
        bufp->chgIData(oldp+86,(vlSelfRef.top__DOT__mcycleh),32);
        bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__mvendorid),32);
        bufp->chgIData(oldp+88,(vlSelfRef.top__DOT__marchid),32);
        bufp->chgIData(oldp+89,(vlSelfRef.top__DOT__mstatus),32);
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__mepc),32);
        bufp->chgIData(oldp+91,(vlSelfRef.top__DOT__mcause),32);
        bufp->chgIData(oldp+92,(vlSelfRef.top__DOT__mtvec),32);
    }
    bufp->chgBit(oldp+93,(vlSelfRef.clk));
    bufp->chgIData(oldp+94,(vlSelfRef.inst),32);
    bufp->chgBit(oldp+95,(vlSelfRef.rst));
    bufp->chgIData(oldp+96,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+97,(vlSelfRef.pc_before),32);
    bufp->chgCData(oldp+98,(vlSelfRef.num),5);
    bufp->chgIData(oldp+99,(vlSelfRef.my_mtvec),32);
    bufp->chgIData(oldp+100,(vlSelfRef.my_mepc),32);
    bufp->chgIData(oldp+101,(vlSelfRef.my_mcause),32);
    bufp->chgIData(oldp+102,(vlSelfRef.my_mstatus),32);
    bufp->chgCData(oldp+103,((0x0000001fU & (vlSelfRef.inst 
                                             >> 7U))),5);
    bufp->chgCData(oldp+104,((0x0000001fU & (vlSelfRef.inst 
                                             >> 0x0000000fU))),5);
    bufp->chgCData(oldp+105,((0x0000001fU & (vlSelfRef.inst 
                                             >> 0x00000014U))),5);
    bufp->chgIData(oldp+106,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->chgIData(oldp+107,((((- (IData)((vlSelfRef.inst 
                                           >> 0x0000001fU))) 
                               << 0x0000000cU) | ((0x00000fe0U 
                                                   & (vlSelfRef.inst 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001fU 
                                                     & (vlSelfRef.inst 
                                                        >> 7U))))),32);
    bufp->chgIData(oldp+108,((((- (IData)((vlSelfRef.inst 
                                           >> 0x0000001fU))) 
                               << 0x0000000cU) | ((0x00000800U 
                                                   & (vlSelfRef.inst 
                                                      << 4U)) 
                                                  | ((0x000007e0U 
                                                      & (vlSelfRef.inst 
                                                         >> 0x00000014U)) 
                                                     | (0x0000001eU 
                                                        & (vlSelfRef.inst 
                                                           >> 7U)))))),32);
    bufp->chgIData(oldp+109,(((((0x00000ffeU & ((- (IData)(
                                                           (vlSelfRef.inst 
                                                            >> 0x0000001fU))) 
                                                << 1U)) 
                                | (vlSelfRef.inst >> 0x0000001fU)) 
                               << 0x00000014U) | ((
                                                   ((0x000001feU 
                                                     & (vlSelfRef.inst 
                                                        >> 0x0000000bU)) 
                                                    | (1U 
                                                       & (vlSelfRef.inst 
                                                          >> 0x00000014U))) 
                                                   << 0x0000000bU) 
                                                  | (0x000007feU 
                                                     & (vlSelfRef.inst 
                                                        >> 0x00000014U))))),32);
    bufp->chgCData(oldp+110,((0x0000007fU & vlSelfRef.inst)),7);
    bufp->chgCData(oldp+111,((7U & (vlSelfRef.inst 
                                    >> 0x0000000cU))),3);
    bufp->chgCData(oldp+112,((vlSelfRef.inst >> 0x00000019U)),7);
    bufp->chgBit(oldp+113,(((0x37U == (0x0000007fU 
                                       & vlSelfRef.inst)) 
                            | ((0x17U == (0x0000007fU 
                                          & vlSelfRef.inst)) 
                               | ((3U == (0x0000007fU 
                                          & vlSelfRef.inst)) 
                                  | ((0x6fU == (0x0000007fU 
                                                & vlSelfRef.inst)) 
                                     | ((0x33U == (0x0000007fU 
                                                   & vlSelfRef.inst)) 
                                        | ((0x13U == 
                                            (0x0000007fU 
                                             & vlSelfRef.inst)) 
                                           | ((IData)(vlSelfRef.top__DOT__my_CU__DOT__is_jalr) 
                                              | (IData)(vlSelfRef.top__DOT__my_CU__DOT__csr_to_reg_en))))))))));
    bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__my_CU__DOT__wdata),32);
    bufp->chgBit(oldp+115,((3U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgCData(oldp+116,(((0x00004000U & vlSelfRef.inst)
                               ? ((0x00002000U & vlSelfRef.inst)
                                   ? 0U : ((0x00001000U 
                                            & vlSelfRef.inst)
                                            ? 2U : 1U))
                               : ((0x00002000U & vlSelfRef.inst)
                                   ? ((0x00001000U 
                                       & vlSelfRef.inst)
                                       ? 0U : 0xffU)
                                   : ((0x00001000U 
                                       & vlSelfRef.inst)
                                       ? 2U : 1U)))),8);
    bufp->chgIData(oldp+117,(vlSelfRef.top__DOT__my_CU__DOT__pc_next),32);
    bufp->chgBit(oldp+118,((0x23U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgCData(oldp+119,(((0U == (7U & (vlSelfRef.inst 
                                            >> 0x0000000cU)))
                               ? ((2U & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                   ? ((1U & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                       ? 8U : 4U) : 
                                  ((1U & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                    ? 2U : 1U)) : (
                                                   (2U 
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
                                                     : 0U)))),8);
    bufp->chgBit(oldp+120,((0x00100073U == vlSelfRef.inst)));
    bufp->chgBit(oldp+121,((0x00000073U == vlSelfRef.inst)));
    bufp->chgBit(oldp+122,((0x30200073U == vlSelfRef.inst)));
    bufp->chgIData(oldp+123,(vlSelfRef.top__DOT__my_CSR_ALU__DOT__csrdata),32);
    bufp->chgIData(oldp+124,(vlSelfRef.top__DOT__my_CSR_ALU__DOT__data1),32);
    bufp->chgCData(oldp+125,((3U & (vlSelfRef.inst 
                                    >> 0x0000000cU))),2);
    bufp->chgBit(oldp+126,((0x37U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+127,((0x17U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+128,((0x6fU == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+129,((0x33U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+130,((0x13U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+131,((0x63U == (0x0000007fU & vlSelfRef.inst))));
    bufp->chgBit(oldp+132,(((0x13U == (0x0000007fU 
                                       & vlSelfRef.inst)) 
                            | (0x33U == (0x0000007fU 
                                         & vlSelfRef.inst)))));
    bufp->chgIData(oldp+133,(((0x00004000U & vlSelfRef.inst)
                               ? ((0x00002000U & vlSelfRef.inst)
                                   ? 0U : ((0x00001000U 
                                            & vlSelfRef.inst)
                                            ? (0x0000ffffU 
                                               & vlSelfRef.top__DOT__mem_read_data)
                                            : (0x000000ffU 
                                               & vlSelfRef.top__DOT__mem_read_data)))
                               : ((0x00002000U & vlSelfRef.inst)
                                   ? ((0x00001000U 
                                       & vlSelfRef.inst)
                                       ? 0U : vlSelfRef.top__DOT__mem_read_data)
                                   : ((0x00001000U 
                                       & vlSelfRef.inst)
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.top__DOT__mem_read_data 
                                                          >> 0x0fU)))) 
                                           << 0x00000010U) 
                                          | (0x0000ffffU 
                                             & vlSelfRef.top__DOT__mem_read_data))
                                       : (((- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.top__DOT__mem_read_data 
                                                          >> 7U)))) 
                                           << 8U) | 
                                          (0x000000ffU 
                                           & vlSelfRef.top__DOT__mem_read_data)))))),32);
    bufp->chgBit(oldp+134,(((0x63U == (0x0000007fU 
                                       & vlSelfRef.inst)) 
                            & ((IData)(((0U == (0x00007000U 
                                                & vlSelfRef.inst)) 
                                        & (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                           == vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                               | ((IData)(((0x00001000U 
                                            == (0x00007000U 
                                                & vlSelfRef.inst)) 
                                           & (vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                                              != vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                  | ((IData)(((0x00004000U 
                                               == (0x00007000U 
                                                   & vlSelfRef.inst)) 
                                              & VL_LTS_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2))) 
                                     | ((IData)(((0x00005000U 
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
                                                         >= vlSelfRef.top__DOT__my_CU__DOT__rdata2)))))))))));
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
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
