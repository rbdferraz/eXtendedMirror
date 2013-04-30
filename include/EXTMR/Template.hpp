/* 
 * File:   Template.hpp
 * Author: Manuele Finocchiaro
 *
 * Created on January 2, 2013, 13.23
 */

#ifndef EXTMR_TEMPLATE_HPP
#define	EXTMR_TEMPLATE_HPP

namespace extmr{

/**
 * Holds some information about template types.
 */
class Template
{
public:
    /**
     * A basic constructor.
     * 
     * @param name The name of the template.
     */
    Template(const std::string& name, uint argN = 0); 
    
    /**
     * Get the name of the template.
     * 
     * @return The template name string.
     */
    const std::string& getName() const;
    
    /**
     * Get the number of the template parameters.
     * 
     * @return The template parameter number.
     */
    uint getArgN() const;
    
    
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


typedef std::set<const Template*, PtrCmpByName<Type> > ConstTemplateSet;
typedef std::set<Template*, PtrCmpByName<Template> > TemplateSet;


} // namespace extmr

#endif	/* EXTMR_TEMPLATE_HPP */
