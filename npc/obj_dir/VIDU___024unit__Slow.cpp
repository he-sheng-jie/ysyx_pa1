// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VIDU.h for the primary calling header

#include "VIDU__pch.h"

void VIDU___024unit___ctor_var_reset(VIDU___024unit* vlSelf);

void VIDU___024unit::ctor(VIDU__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    VIDU___024unit___ctor_var_reset(this);
}

void VIDU___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void VIDU___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
