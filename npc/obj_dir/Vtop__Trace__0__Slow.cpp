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
    tracep->declBit(c+81,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+83,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"pc_before",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"num",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+81,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+83,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"pc_before",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"num",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+87,0,"pc_before_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+89,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+90,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"imm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"imm_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+96,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+97,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+98,0,"wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+100,0,"mem_to_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"mem_to_reg_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+6,0,"mem_to_reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"mem_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+103,0,"reg_to_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+8,0,"reg_to_mem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"reg_to_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+105,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("GPR", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+115,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+98,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+90,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("debug_rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+17+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+49+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("my_CU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"rdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"imm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"imm_u",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"imm_s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"imm_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"imm_j",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+96,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+97,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+7,0,"mem_read_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+98,0,"wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"pc_next",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+103,0,"reg_to_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+8,0,"reg_to_mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"reg_to_mem_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+100,0,"mem_to_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"mem_to_reg_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+105,0,"is_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"is_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"is_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"is_i_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"is_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"is_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"branch_eq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"alu_num2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"mem_to_reg_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+11,0,"branch_ne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"branch_lt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"branch_ge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"branch_ltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"branch_geu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+16,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("my_ALU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+3,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+4,0,"num1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"num2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("my_IDU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+89,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+90,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"imm_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"imm_u",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"imm_s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"imm_b",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"imm_j",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+96,0,"funct3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+97,0,"funct7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
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
    bufp->fullIData(oldp+115,(5U),32);
    bufp->fullIData(oldp+116,(0x00000020U),32);
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
    bufp->fullIData(oldp+1,(vlSelfRef.top__DOT__my_CU__DOT__imm_i),32);
    bufp->fullBit(oldp+2,(vlSelfRef.top__DOT__my_CU__DOT__is_jalr));
    bufp->fullCData(oldp+3,(vlSelfRef.top__DOT__my_CU__DOT__alu_op),4);
    bufp->fullIData(oldp+4,(vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1),32);
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__my_CU__DOT__rdata2),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__mem_to_reg_addr),32);
    bufp->fullIData(oldp+7,(vlSelfRef.top__DOT__mem_read_data),32);
    bufp->fullIData(oldp+8,(vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr),32);
    bufp->fullBit(oldp+9,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                           == vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num2),32);
    bufp->fullBit(oldp+11,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                            != vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
    bufp->fullBit(oldp+12,(VL_LTS_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
    bufp->fullBit(oldp+13,(VL_GTES_III(32, vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1, vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
    bufp->fullBit(oldp+14,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                            < vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
    bufp->fullBit(oldp+15,((vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__num1 
                            >= vlSelfRef.top__DOT__my_CU__DOT__rdata2)));
    bufp->fullIData(oldp+16,(vlSelfRef.top__DOT__my_CU__DOT__my_ALU__DOT__alu_result),32);
    bufp->fullIData(oldp+17,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[0]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[1]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[2]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[3]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[4]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[5]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[6]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[7]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[8]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[9]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[10]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[11]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[12]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[13]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[14]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[15]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[16]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[17]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[18]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[19]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[20]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[21]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[22]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[23]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[24]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[25]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[26]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[27]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[28]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[29]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[30]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.top__DOT__GPR__DOT__debug_rf[31]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.top__DOT__GPR__DOT__rf[0]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.top__DOT__GPR__DOT__rf[1]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.top__DOT__GPR__DOT__rf[2]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.top__DOT__GPR__DOT__rf[3]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.top__DOT__GPR__DOT__rf[4]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.top__DOT__GPR__DOT__rf[5]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.top__DOT__GPR__DOT__rf[6]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.top__DOT__GPR__DOT__rf[7]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.top__DOT__GPR__DOT__rf[8]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__GPR__DOT__rf[9]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__GPR__DOT__rf[10]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__GPR__DOT__rf[11]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.top__DOT__GPR__DOT__rf[12]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.top__DOT__GPR__DOT__rf[13]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.top__DOT__GPR__DOT__rf[14]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.top__DOT__GPR__DOT__rf[15]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.top__DOT__GPR__DOT__rf[16]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.top__DOT__GPR__DOT__rf[17]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.top__DOT__GPR__DOT__rf[18]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.top__DOT__GPR__DOT__rf[19]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.top__DOT__GPR__DOT__rf[20]),32);
    bufp->fullIData(oldp+70,(vlSelfRef.top__DOT__GPR__DOT__rf[21]),32);
    bufp->fullIData(oldp+71,(vlSelfRef.top__DOT__GPR__DOT__rf[22]),32);
    bufp->fullIData(oldp+72,(vlSelfRef.top__DOT__GPR__DOT__rf[23]),32);
    bufp->fullIData(oldp+73,(vlSelfRef.top__DOT__GPR__DOT__rf[24]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.top__DOT__GPR__DOT__rf[25]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.top__DOT__GPR__DOT__rf[26]),32);
    bufp->fullIData(oldp+76,(vlSelfRef.top__DOT__GPR__DOT__rf[27]),32);
    bufp->fullIData(oldp+77,(vlSelfRef.top__DOT__GPR__DOT__rf[28]),32);
    bufp->fullIData(oldp+78,(vlSelfRef.top__DOT__GPR__DOT__rf[29]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.top__DOT__GPR__DOT__rf[30]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.top__DOT__GPR__DOT__rf[31]),32);
    bufp->fullBit(oldp+81,(vlSelfRef.clk));
    bufp->fullIData(oldp+82,(vlSelfRef.inst),32);
    bufp->fullBit(oldp+83,(vlSelfRef.rst));
    bufp->fullIData(oldp+84,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+85,(vlSelfRef.pc_before),32);
    bufp->fullCData(oldp+86,(vlSelfRef.num),5);
    bufp->fullIData(oldp+87,(vlSelfRef.top__DOT__pc_before_reg),32);
    bufp->fullCData(oldp+88,((0x0000001fU & (vlSelfRef.inst 
                                             >> 7U))),5);
    bufp->fullCData(oldp+89,((0x0000001fU & (vlSelfRef.inst 
                                             >> 0x0000000fU))),5);
    bufp->fullCData(oldp+90,((0x0000001fU & (vlSelfRef.inst 
                                             >> 0x00000014U))),5);
    bufp->fullIData(oldp+91,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->fullIData(oldp+92,((((- (IData)((vlSelfRef.inst 
                                           >> 0x0000001fU))) 
                               << 0x0000000cU) | ((0x00000fe0U 
                                                   & (vlSelfRef.inst 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001fU 
                                                     & (vlSelfRef.inst 
                                                        >> 7U))))),32);
    bufp->fullIData(oldp+93,((((- (IData)((vlSelfRef.inst 
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
    bufp->fullIData(oldp+94,(((((0x00000ffeU & ((- (IData)(
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
    bufp->fullCData(oldp+95,((0x0000007fU & vlSelfRef.inst)),7);
    bufp->fullCData(oldp+96,((7U & (vlSelfRef.inst 
                                    >> 0x0000000cU))),3);
    bufp->fullCData(oldp+97,((vlSelfRef.inst >> 0x00000019U)),7);
    bufp->fullBit(oldp+98,(((0x37U == (0x0000007fU 
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
                                           | (IData)(vlSelfRef.top__DOT__my_CU__DOT__is_jalr)))))))));
    bufp->fullIData(oldp+99,(vlSelfRef.top__DOT__my_CU__DOT__wdata),32);
    bufp->fullBit(oldp+100,((3U == (0x0000007fU & vlSelfRef.inst))));
    bufp->fullCData(oldp+101,(((0x00004000U & vlSelfRef.inst)
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
    bufp->fullIData(oldp+102,(vlSelfRef.top__DOT__my_CU__DOT__pc_next),32);
    bufp->fullBit(oldp+103,((0x23U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullCData(oldp+104,(((0U == (7U & (vlSelfRef.inst 
                                             >> 0x0000000cU)))
                                ? ((2U & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                    ? ((1U & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                        ? 8U : 4U) : 
                                   ((1U & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                     ? 2U : 1U)) : 
                               ((2U == (7U & (vlSelfRef.inst 
                                              >> 0x0000000cU)))
                                 ? 0xffU : ((1U == 
                                             (7U & 
                                              (vlSelfRef.inst 
                                               >> 0x0000000cU)))
                                             ? ((2U 
                                                 & vlSelfRef.top__DOT__my_CU__DOT__reg_to_mem_addr)
                                                 ? 0x0cU
                                                 : 3U)
                                             : 0U)))),8);
    bufp->fullBit(oldp+105,((0x00100073U == vlSelfRef.inst)));
    bufp->fullBit(oldp+106,((0x37U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+107,((0x17U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+108,((0x6fU == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+109,((0x33U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+110,((0x13U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+111,((0x63U == (0x0000007fU 
                                       & vlSelfRef.inst))));
    bufp->fullBit(oldp+112,(((0x13U == (0x0000007fU 
                                        & vlSelfRef.inst)) 
                             | (0x33U == (0x0000007fU 
                                          & vlSelfRef.inst)))));
    bufp->fullIData(oldp+113,(((0x00004000U & vlSelfRef.inst)
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
                                            << 8U) 
                                           | (0x000000ffU 
                                              & vlSelfRef.top__DOT__mem_read_data)))))),32);
    bufp->fullBit(oldp+114,(((0x63U == (0x0000007fU 
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
                                                == 
                                                (0x00007000U 
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
