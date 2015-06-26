/******************************************************************************      
 *      Extended Mirror: Template.hpp                                         *
 ******************************************************************************
 *      Copyright (c) 2012-2015, Manuele Finocchiaro                          *
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


#ifndef XM_DECLARE_TEMPLATE_HPP
#define	XM_DECLARE_TEMPLATE_HPP

namespace xm{

/**
 * Holds some information about template types.
 */
class Template : public Item
{
public:
    /**
     * A basic constructor.
     * 
     * @param uName The unqualified name of the template.
     */
    Template(const std::string& name, uint argN = 0); 

    /**
     * A basic constructor.
     *
     * @param uName The unqualified name of the template.
     */
    Template(const std::string& uName, const Namespace& name_space);
    
    /**
     * Get the number of the template parameters.
     * 
     * @return The template parameter number.
     */
    uint getArgN() const;

    Item::Category getItemCategory() const;
    
    /**
     * Not valid Template.
     * This template is used wherever reference to a non valid template is 
     * needed.
     */
    static const Template None;
    
private:
    
    // The name of the template.
    std::string name_;
    
    // The number of arguments.
    uint argN_;
};


} // namespace xm

#endif	/* XM_DECLARE_TEMPLATE_HPP */

