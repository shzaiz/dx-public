import lldb

def set_global_var_breakpoints():
    target = lldb.debugger.GetSelectedTarget()
    module = target.GetModuleAtIndex(0)
    global_variables = module.FindGlobalVariables(target, lldb.DBG_NO_OPTIONS)

    for var in global_variables:
        name = var.GetName()
        breakpoint = target.BreakpointCreateByName(name, module.GetFileSpec())
        print(f"Breakpoint set for global variable: {name}")

# Call the function to set the breakpoints when the script is loaded
set_global_var_breakpoints()
