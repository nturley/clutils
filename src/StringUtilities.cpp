// Copyright (c) 2000-2002 Clifton Labs, Inc.  
// All rights reserved.

// Clifton Labs MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  Clifton Labs SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Dale E. Martin   dmartin@cliftonlabs.com

#include "StringUtilities.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <string>

using std::ends;
using std::string;
using std::stringstream;

extern "C" {
    int fake(void) {
        return 0;
    }
}

const string doubleToString( double input ){
  stringstream stream;
  stream << input;
  return stream.str();
}

const string upperCase( const string &inputString ){
  string retval;
  for(unsigned int i = 0; i < inputString.length(); i++){
    retval += toupper( inputString[i] );
  }
  return retval;
}

const string trimWhiteSpaces( const string &inputString ){
  string retval;
  unsigned char value;
  while((value = retval.find(" ")) != string::npos){
    retval.erase(value, strlen(" "));
  }
  return retval;
}

const string intToString( int input ){
  return std::to_string(input);
}

int stringToInt( const string &input ){
  try
  {
    return stoi(input);
  }
  catch (int e)
  {
    return -1;
  }
}

double stringToDouble( const string &input ){
  try
  {
    return stod(input);
  }
  catch (int e)
  {
    return 0.0;
  }
}

bool stringCaseCompare( const string &s1, const string &s2 ){
  bool retval = (upperCase( s1 ) == upperCase( s2 ));
  return retval;
}

long
stringToLong( const string &input, int &endPos ){
  long retval = -1;

  char *endPtr = 0;
  retval = strtol( input.c_str(), &endPtr, 10 );
  endPos = endPtr - input.c_str();
  
  return retval;
}
