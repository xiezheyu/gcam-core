#ifndef _TRAN_SUBSECTOR_H_
#define _TRAN_SUBSECTOR_H_
#if defined(_MSC_VER)
#pragma once
#endif

/* transSubSector.h									*
* This header contains the Specialized Transportation SubSector
* MAW  3/11/03						
* Revised to work with latest code.
* SHK  6/30/03
*/

#include <vector>
#include <string>
#include <xercesc/dom/DOM.hpp>
#include "subsector.h"

// transportation demand subsector class derived from base subsector class
// Modes of transportation are implemented as subsectors
class tranSubsector : public Subsector
{
protected:
    std::vector<double> speed; // Speed of Mode in Miles/hour
    std::vector<double> popDenseElasticity; // Population Density Elasticity of mode
    std::vector<double> servicePrice; // subsector price converted to $/pass-mi or $/ton-mi
    std::vector<double> timeValue; // time value of average modal speed
    std::vector<double> generalizedCost; // subsector price adjusted for value of time, scaled by pd.
    std::vector<double> loadFactor; //Load factor, persons or tons per vehicle (pass./freight)
    double popDensity; // population density per land area
    double baseScaler; // constant scaler to scale base output
    
public:
    tranSubsector( std::string regionName, std::string sectorName );
    virtual void clear();
    virtual void XMLDerivedClassParse( const std::string nodeName, const xercesc::DOMNode* curr ); // for derived classes
    virtual void calcShare(const int period, const double gnp_cap = 1 ); 
    virtual void setoutput( const double demand, const int period );
    
};


#endif // _TRAN_SUBSECTOR_H_