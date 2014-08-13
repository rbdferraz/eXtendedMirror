
/******************************************************************************      
 *      Extended Mirror: BindFunction.hpp                                     *
 ******************************************************************************
 *      Copyright (c) 2012-2014, Manuele Finocchiaro                          *
 *      All rights reserved.                                                  *
 ******************************************************************************
 * Redistribution and use in source and binary forms, with or without         *
 * modification, are permitted provided that the following conditions         *
 * are met:                                                                   *
 *                                                                            *
 *    1. Redistributions of source code must retain the above copyright       *
 *       notice, this list of conditions and the following disclaimer.        *
 *                                                                            *
 *    2. Redistributions in binary form must reproduce the above copyright    *
 *       notice, this list of conditions and the following disclaimer in      *
 *       the documentation and/or other materials provided with the           *
 *       distribution.                                                        *
 *                                                                            *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"* 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE *
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  *
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        *
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF       *
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   *
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    *
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    *
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF     *
 * THE POSSIBILITY OF SUCH DAMAGE.                                            *
 *****************************************************************************/

/* WARNING: This file has been autogenerated. do not modify it directly! */

#ifndef XM_BINDFUNCTION_HPP
#define	XM_BINDFUNCTION_HPP


#define XM_FUNCTION_PARAM_MAX 8


namespace xm {


template
<
    typename RetT
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
    )
)
{
    // ensure the types are registered
    registerType<RetT>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_0_Params
        <
            RetT
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_1_Params
        <
            RetT,
            ParamT0
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_2_Params
        <
            RetT,
            ParamT0,
            ParamT1
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1,
        ParamT2
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_3_Params
        <
            RetT,
            ParamT0,
            ParamT1,
            ParamT2
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_4_Params
        <
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_5_Params
        <
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_6_Params
        <
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5,
    typename ParamT6
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5,
        ParamT6
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();
    registerType<ParamT6>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_7_Params
        <
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5,
            ParamT6
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}


template
<
    typename RetT,
    typename ParamT0,
    typename ParamT1,
    typename ParamT2,
    typename ParamT3,
    typename ParamT4,
    typename ParamT5,
    typename ParamT6,
    typename ParamT7
>
Function& bindFunction
(
    const std::string& name,
    Namespace& name_space,
    RetT (*function)
    ( 
        ParamT0,
        ParamT1,
        ParamT2,
        ParamT3,
        ParamT4,
        ParamT5,
        ParamT6,
        ParamT7
    )
)
{
    // ensure the types are registered
    registerType<RetT>();
    registerType<ParamT0>();
    registerType<ParamT1>();
    registerType<ParamT2>();
    registerType<ParamT3>();
    registerType<ParamT4>();
    registerType<ParamT5>();
    registerType<ParamT6>();
    registerType<ParamT7>();

    // create the proper Function
    Function* xmFunction = new FunctionImpl_8_Params
        <
            RetT,
            ParamT0,
            ParamT1,
            ParamT2,
            ParamT3,
            ParamT4,
            ParamT5,
            ParamT6,
            ParamT7
        >
        ( name, function );
    name_space.addItem(*xmFunction);
    return *xmFunction;
}



} // namespace xm

#endif	/* XM_BINDFUNCTION_HPP */