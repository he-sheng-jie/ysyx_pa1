// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VEXU__Syms.h"


VL_ATTR_COLD void VEXU___024root__trace_init_sub__TOP__0(VEXU___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_init_sub__TOP__0\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+35,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+35,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+39,0,"wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+2,0,"rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+42,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"is_addi_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"is_jalr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"ALU_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("GPR", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+60,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+35,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+39,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+59,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+3+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("my_EXU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+47,0,"is_addi_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"is_jalr_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"rdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"imm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"imm_u",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"imm_s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"ALU_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"num1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"num2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("my_IDU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+36,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+42,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"imm_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"imm_u",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"imm_s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"is_addi_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"is_jalr_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+51,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+52,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+53,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"f30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"f32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"f34",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VEXU___024root__trace_init_top(VEXU___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_init_top\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VEXU___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VEXU___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VEXU___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VEXU___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VEXU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VEXU___024root__trace_register(VEXU___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_register\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VEXU___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VEXU___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VEXU___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VEXU___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VEXU___024root__trace_const_0_sub_0(VEXU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VEXU___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_const_0\n"); );
    // Body
    VEXU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VEXU___024root*>(voidSelf);
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VEXU___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VEXU___024root__trace_const_0_sub_0(VEXU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_const_0_sub_0\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+58,(vlSelfRef.top__DOT__raddr1),5);
    bufp->fullCData(oldp+59,(vlSelfRef.top__DOT__raddr2),5);
    bufp->fullIData(oldp+60,(5U),32);
    bufp->fullIData(oldp+61,(0x00000020U),32);
}

VL_ATTR_COLD void VEXU___024root__trace_full_0_sub_0(VEXU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VEXU___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_full_0\n"); );
    // Body
    VEXU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VEXU___024root*>(voidSelf);
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VEXU___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VEXU___024root__trace_full_0_sub_0(VEXU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEXU___024root__trace_full_0_sub_0\n"); );
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.top__DOT__GPR__DOT__rf
                            [vlSelfRef.top__DOT__raddr1]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.top__DOT__GPR__DOT__rf
                            [vlSelfRef.top__DOT__raddr2]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.top__DOT__GPR__DOT__rf[0]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.top__DOT__GPR__DOT__rf[1]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__GPR__DOT__rf[2]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__GPR__DOT__rf[3]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.top__DOT__GPR__DOT__rf[4]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.top__DOT__GPR__DOT__rf[5]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__GPR__DOT__rf[6]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__GPR__DOT__rf[7]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.top__DOT__GPR__DOT__rf[8]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.top__DOT__GPR__DOT__rf[9]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.top__DOT__GPR__DOT__rf[10]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.top__DOT__GPR__DOT__rf[11]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.top__DOT__GPR__DOT__rf[12]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.top__DOT__GPR__DOT__rf[13]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.top__DOT__GPR__DOT__rf[14]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.top__DOT__GPR__DOT__rf[15]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.top__DOT__GPR__DOT__rf[16]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.top__DOT__GPR__DOT__rf[17]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.top__DOT__GPR__DOT__rf[18]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__GPR__DOT__rf[19]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__GPR__DOT__rf[20]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__GPR__DOT__rf[21]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.top__DOT__GPR__DOT__rf[22]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.top__DOT__GPR__DOT__rf[23]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__GPR__DOT__rf[24]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__GPR__DOT__rf[25]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__GPR__DOT__rf[26]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__GPR__DOT__rf[27]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__GPR__DOT__rf[28]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__GPR__DOT__rf[29]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__GPR__DOT__rf[30]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.top__DOT__GPR__DOT__rf[31]),32);
    bufp->fullBit(oldp+35,(vlSelfRef.clk));
    bufp->fullIData(oldp+36,(vlSelfRef.inst),32);
    bufp->fullIData(oldp+37,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+38,(vlSelfRef.result),32);
    bufp->fullBit(oldp+39,(((IData)((0x00000013U == 
                                     (0x0000707fU & vlSelfRef.inst))) 
                            | (IData)(vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok))));
    bufp->fullIData(oldp+40,(((IData)(vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok)
                               ? ((IData)(4U) + vlSelfRef.pc)
                               : vlSelfRef.top__DOT__my_EXU__DOT__ALU_result)),32);
    bufp->fullCData(oldp+41,((0x0000001fU & (vlSelfRef.inst 
                                             >> 7U))),5);
    bufp->fullCData(oldp+42,((0x0000001fU & (vlSelfRef.inst 
                                             >> 0x0000000fU))),5);
    bufp->fullCData(oldp+43,((0x0000001fU & (vlSelfRef.inst 
                                             >> 0x00000014U))),5);
    bufp->fullIData(oldp+44,((((- (IData)((vlSelfRef.inst 
                                           >> 0x0000001fU))) 
                               << 0x0000000cU) | (vlSelfRef.inst 
                                                  >> 0x00000014U))),32);
    bufp->fullIData(oldp+45,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->fullIData(oldp+46,((((- (IData)((vlSelfRef.inst 
                                           >> 0x0000001fU))) 
                               << 0x0000000cU) | ((0x00000fe0U 
                                                   & (vlSelfRef.inst 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001fU 
                                                     & (vlSelfRef.inst 
                                                        >> 7U))))),32);
    bufp->fullBit(oldp+47,((IData)((0x00000013U == 
                                    (0x0000707fU & vlSelfRef.inst)))));
    bufp->fullBit(oldp+48,(vlSelfRef.top__DOT__my_EXU__DOT__is_jalr_ok));
    bufp->fullIData(oldp+49,(vlSelfRef.top__DOT__my_EXU__DOT__ALU_result),32);
    bufp->fullCData(oldp+50,((0x0000007fU & vlSelfRef.inst)),7);
    bufp->fullCData(oldp+51,((7U & (vlSelfRef.inst 
                                    >> 0x0000000cU))),3);
    bufp->fullCData(oldp+52,((vlSelfRef.inst >> 0x00000019U)),7);
    bufp->fullBit(oldp+53,((0x13U == (0x0000007fU & vlSelfRef.inst))));
    bufp->fullBit(oldp+54,((0x67U == (0x0000007fU & vlSelfRef.inst))));
    bufp->fullBit(oldp+55,((0U == (7U & (vlSelfRef.inst 
                                         >> 0x0000000cU)))));
    bufp->fullBit(oldp+56,((2U == (7U & (vlSelfRef.inst 
                                         >> 0x0000000cU)))));
    bufp->fullBit(oldp+57,((4U == (7U & (vlSelfRef.inst 
                                         >> 0x0000000cU)))));
}
