/* 
 * File:   VariantCostnessException.cpp
 * Author: Manuele Finocchiaro
 * 
 * Created on 22 January 2013, 18.56
 */

#include <Common/Common.hpp>
#include <EXTMR/ExtendedMirror.hpp>

using namespace extmr;
using namespace std;

VariantCostnessException::VariantCostnessException(const Type& type) throw()
        : type_(type)
{
}

const char* VariantCostnessException::what() const throw()
{
    return (string("Cannot convert variant of type const ")
            + type_.getName()
            + " to type "
            + type_.getName() + ".").c_str();
}
