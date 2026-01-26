// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VIDU__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VIDU::VIDU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VIDU__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , num{vlSymsp->TOP.num}
    , inst{vlSymsp->TOP.inst}
    , pc{vlSymsp->TOP.pc}
    , pc_before{vlSymsp->TOP.pc_before}
    , debug_rf{vlSymsp->TOP.debug_rf}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VIDU::VIDU(const char* _vcname__)
    : VIDU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VIDU::~VIDU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VIDU___024root___eval_debug_assertions(VIDU___024root* vlSelf);
#endif  // VL_DEBUG
void VIDU___024root___eval_static(VIDU___024root* vlSelf);
void VIDU___024root___eval_initial(VIDU___024root* vlSelf);
void VIDU___024root___eval_settle(VIDU___024root* vlSelf);
void VIDU___024root___eval(VIDU___024root* vlSelf);

void VIDU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VIDU::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VIDU___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VIDU___024root___eval_static(&(vlSymsp->TOP));
        VIDU___024root___eval_initial(&(vlSymsp->TOP));
        VIDU___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VIDU___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VIDU::eventsPending() { return false; }

uint64_t VIDU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VIDU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VIDU___024root___eval_final(VIDU___024root* vlSelf);

VL_ATTR_COLD void VIDU::final() {
    VIDU___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VIDU::hierName() const { return vlSymsp->name(); }
const char* VIDU::modelName() const { return "VIDU"; }
unsigned VIDU::threads() const { return 1; }
void VIDU::prepareClone() const { contextp()->prepareClone(); }
void VIDU::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VIDU::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VIDU___024root__trace_decl_types(VerilatedVcd* tracep);

void VIDU___024root__trace_init_top(VIDU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VIDU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VIDU___024root*>(voidSelf);
    VIDU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VIDU___024root__trace_decl_types(tracep);
    VIDU___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VIDU___024root__trace_register(VIDU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VIDU::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VIDU::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VIDU___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
