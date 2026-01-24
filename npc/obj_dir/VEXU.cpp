// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VEXU__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VEXU::VEXU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VEXU__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , inst{vlSymsp->TOP.inst}
    , pc{vlSymsp->TOP.pc}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VEXU::VEXU(const char* _vcname__)
    : VEXU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VEXU::~VEXU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VEXU___024root___eval_debug_assertions(VEXU___024root* vlSelf);
#endif  // VL_DEBUG
void VEXU___024root___eval_static(VEXU___024root* vlSelf);
void VEXU___024root___eval_initial(VEXU___024root* vlSelf);
void VEXU___024root___eval_settle(VEXU___024root* vlSelf);
void VEXU___024root___eval(VEXU___024root* vlSelf);

void VEXU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VEXU::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VEXU___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VEXU___024root___eval_static(&(vlSymsp->TOP));
        VEXU___024root___eval_initial(&(vlSymsp->TOP));
        VEXU___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VEXU___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VEXU::eventsPending() { return false; }

uint64_t VEXU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VEXU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VEXU___024root___eval_final(VEXU___024root* vlSelf);

VL_ATTR_COLD void VEXU::final() {
    VEXU___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VEXU::hierName() const { return vlSymsp->name(); }
const char* VEXU::modelName() const { return "VEXU"; }
unsigned VEXU::threads() const { return 1; }
void VEXU::prepareClone() const { contextp()->prepareClone(); }
void VEXU::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VEXU::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VEXU___024root__trace_decl_types(VerilatedVcd* tracep);

void VEXU___024root__trace_init_top(VEXU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VEXU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VEXU___024root*>(voidSelf);
    VEXU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VEXU___024root__trace_decl_types(tracep);
    VEXU___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VEXU___024root__trace_register(VEXU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VEXU::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VEXU::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VEXU___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
