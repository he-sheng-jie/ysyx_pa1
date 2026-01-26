// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+105,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+107,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+108,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"pc_before",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"num",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+105,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+107,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+108,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"pc_before",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"num",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+111,0,"pc_before_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+113,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+116,0,"rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+118,0,"rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+110,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+117,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+120,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+123,0,"is_addi_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"is_jalr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"is_add_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"is_lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"is_lbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"is_sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"is_sb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"is_memtoreg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"ALU_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"pmemdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"memdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"writrtomem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("my_EXU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+2,0,"is_add_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"is_lui",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"is_sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"is_sb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+116,0,"rdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"imm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"imm_u",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"imm_s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"ALU_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"num1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"num2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"imm_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("my_IDU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+106,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+117,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+120,0,"imm_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"imm_u",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"imm_s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+123,0,"is_addi_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"is_add_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"is_jalr_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"is_lui",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"is_lw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"is_lbu",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"is_sw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"is_sb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"is_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+132,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+133,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+134,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+135,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"is_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"is_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"f30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"f32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"f34",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"f70",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("my_WBU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+144,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+105,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"ALU_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+114,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"is_jalr_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+116,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("debug_rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+9+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("GPR", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+144,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+105,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+114,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+116,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("debug_rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+41+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+73+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+144,(5U),32);
    bufp->fullIData(oldp+145,(0x00000020U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.top__DOT__is_jalr_ok));
    bufp->fullBit(oldp+2,(vlSelfRef.top__DOT__is_add_ok));
    bufp->fullBit(oldp+3,(vlSelfRef.top__DOT__is_lw));
    bufp->fullBit(oldp+4,(vlSelfRef.top__DOT__is_sw));
    bufp->fullBit(oldp+5,(vlSelfRef.top__DOT__is_sb));
    bufp->fullBit(oldp+6,(vlSelfRef.top__DOT__is_memtoreg));
    bufp->fullBit(oldp+7,(((IData)(vlSelfRef.top__DOT__is_sb) 
                           | (IData)(vlSelfRef.top__DOT__is_sw))));
    bufp->fullIData(oldp+8,(vlSelfRef.top__DOT__pmemdata),32);
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[0]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[1]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[2]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[3]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[4]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[5]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[6]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[7]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[8]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[9]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[10]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[11]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[12]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[13]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[14]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[15]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[16]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[17]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[18]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[19]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[20]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[21]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[22]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[23]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[24]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[25]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[26]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[27]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[28]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[29]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[30]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.top__DOT__my_WBU__DOT__debug_rf[31]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[0]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[1]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[2]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[3]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[4]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[5]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[6]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[7]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[8]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[9]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[10]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[11]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[12]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[13]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[14]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[15]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[16]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[17]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[18]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[19]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[20]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[21]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[22]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[23]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[24]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[25]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[26]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[27]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[28]),32);
    bufp->fullIData(oldp+70,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[29]),32);
    bufp->fullIData(oldp+71,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[30]),32);
    bufp->fullIData(oldp+72,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__debug_rf[31]),32);
    bufp->fullIData(oldp+73,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[0]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[1]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[2]),32);
    bufp->fullIData(oldp+76,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[3]),32);
    bufp->fullIData(oldp+77,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[4]),32);
    bufp->fullIData(oldp+78,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[5]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[6]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[7]),32);
    bufp->fullIData(oldp+81,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[8]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[9]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[10]),32);
    bufp->fullIData(oldp+84,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[11]),32);
    bufp->fullIData(oldp+85,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[12]),32);
    bufp->fullIData(oldp+86,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[13]),32);
    bufp->fullIData(oldp+87,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[14]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[15]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[16]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[17]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[18]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[19]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[20]),32);
    bufp->fullIData(oldp+94,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[21]),32);
    bufp->fullIData(oldp+95,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[22]),32);
    bufp->fullIData(oldp+96,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[23]),32);
    bufp->fullIData(oldp+97,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[24]),32);
    bufp->fullIData(oldp+98,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[25]),32);
    bufp->fullIData(oldp+99,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[26]),32);
    bufp->fullIData(oldp+100,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[27]),32);
    bufp->fullIData(oldp+101,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[28]),32);
    bufp->fullIData(oldp+102,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[29]),32);
    bufp->fullIData(oldp+103,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[30]),32);
    bufp->fullIData(oldp+104,(vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf[31]),32);
    bufp->fullBit(oldp+105,(vlSelfRef.clk));
    bufp->fullIData(oldp+106,(vlSelfRef.inst),32);
    bufp->fullBit(oldp+107,(vlSelfRef.rst));
    bufp->fullIData(oldp+108,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+109,(vlSelfRef.pc_before),32);
    bufp->fullCData(oldp+110,(vlSelfRef.num),5);
    bufp->fullIData(oldp+111,(vlSelfRef.top__DOT__pc_before_reg),32);
    bufp->fullIData(oldp+112,(((IData)(4U) + vlSelfRef.pc)),32);
    bufp->fullBit(oldp+113,((0x00100073U == vlSelfRef.inst)));
    bufp->fullBit(oldp+114,(((IData)((0x00000013U == 
                                      (0x0000707fU 
                                       & vlSelfRef.inst))) 
                             | ((IData)(vlSelfRef.top__DOT__is_jalr_ok) 
                                | ((0x37U == (0x0000007fU 
                                              & vlSelfRef.inst)) 
                                   | ((3U == (0x0000007fU 
                                              & vlSelfRef.inst)) 
                                      | (IData)(vlSelfRef.top__DOT__is_add_ok)))))));
    bufp->fullIData(oldp+115,(((IData)(vlSelfRef.top__DOT__is_memtoreg)
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
                                    ? ((IData)(4U) 
                                       + vlSelfRef.pc)
                                    : vlSelfRef.top__DOT__ALU_result))),32);
    bufp->fullIData(oldp+116,(((0U == (0x0000001fU 
                                       & (vlSelfRef.inst 
                                          >> 0x0000000fU)))
                                ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                               [(0x0000001fU & (vlSelfRef.inst 
                                                >> 0x0000000fU))])),32);
    bufp->fullCData(oldp+117,((0x0000001fU & (vlSelfRef.inst 
                                              >> 0x0000000fU))),5);
    bufp->fullIData(oldp+118,(((0U == (0x0000001fU 
                                       & (vlSelfRef.inst 
                                          >> 0x00000014U)))
                                ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                               [(0x0000001fU & (vlSelfRef.inst 
                                                >> 0x00000014U))])),32);
    bufp->fullCData(oldp+119,((0x0000001fU & (vlSelfRef.inst 
                                              >> 0x00000014U))),5);
    bufp->fullIData(oldp+120,((((- (IData)((vlSelfRef.inst 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.inst 
                                                   >> 0x00000014U))),32);
    bufp->fullIData(oldp+121,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->fullIData(oldp+122,((((- (IData)((vlSelfRef.inst 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000fe0U 
                                                    & (vlSelfRef.inst 
                                                       >> 0x00000014U)) 
                                                   | (IData)(vlSelfRef.num)))),32);
    bufp->fullBit(oldp+123,((IData)((0x00000013U == 
                                     (0x0000707fU & vlSelfRef.inst)))));
    bufp->fullBit(oldp+124,((0x37U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+125,((IData)((0x00004003U == 
                                     (0x0000707fU & vlSelfRef.inst)))));
    bufp->fullIData(oldp+126,(vlSelfRef.top__DOT__ALU_result),32);
    bufp->fullIData(oldp+127,(((IData)(vlSelfRef.top__DOT__is_lw)
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
    bufp->fullCData(oldp+128,(((IData)(vlSelfRef.top__DOT__is_sw)
                                ? 0xffU : ((IData)(vlSelfRef.top__DOT__is_sb)
                                            ? ((2U 
                                                & vlSelfRef.top__DOT__ALU_result)
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__ALU_result)
                                                    ? 8U
                                                    : 4U)
                                                : (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__ALU_result)
                                                    ? 2U
                                                    : 1U))
                                            : 0U))),8);
    bufp->fullIData(oldp+129,(((0x37U == (0x0000007fU 
                                          & vlSelfRef.inst))
                                ? 0U : ((0U == (0x0000001fU 
                                                & (vlSelfRef.inst 
                                                   >> 0x0000000fU)))
                                         ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                        [(0x0000001fU 
                                          & (vlSelfRef.inst 
                                             >> 0x0000000fU))]))),32);
    bufp->fullIData(oldp+130,(((IData)(vlSelfRef.top__DOT__is_add_ok)
                                ? ((0U == (0x0000001fU 
                                           & (vlSelfRef.inst 
                                              >> 0x00000014U)))
                                    ? 0U : vlSelfRef.top__DOT__my_WBU__DOT__GPR__DOT__rf
                                   [(0x0000001fU & 
                                     (vlSelfRef.inst 
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
    bufp->fullIData(oldp+131,((((IData)(vlSelfRef.top__DOT__is_sb) 
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
                                          >> 0x00000014U))))),32);
    bufp->fullCData(oldp+132,((0x0000007fU & vlSelfRef.inst)),7);
    bufp->fullCData(oldp+133,((7U & (vlSelfRef.inst 
                                     >> 0x0000000cU))),3);
    bufp->fullCData(oldp+134,((vlSelfRef.inst >> 0x00000019U)),7);
    bufp->fullBit(oldp+135,((0x13U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+136,((0x67U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+137,((0x33U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+138,((3U == (0x0000007fU & vlSelfRef.inst))));
    bufp->fullBit(oldp+139,((0x23U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+140,((0U == (7U & (vlSelfRef.inst 
                                          >> 0x0000000cU)))));
    bufp->fullBit(oldp+141,((2U == (7U & (vlSelfRef.inst 
                                          >> 0x0000000cU)))));
    bufp->fullBit(oldp+142,((4U == (7U & (vlSelfRef.inst 
                                          >> 0x0000000cU)))));
    bufp->fullBit(oldp+143,((0U == (vlSelfRef.inst 
                                    >> 0x00000019U))));
}
