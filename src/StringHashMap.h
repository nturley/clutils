#ifndef STRING_HASH_MAP_H
#define STRING_HASH_MAP_H

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

#include "clutils-config.h"

#include "StringUtilities.h"

#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>

using std::unordered_map;
using std::string;
using std::vector;

class hashString {
public:
  size_t operator()( const std::string &s ) const;
};

class hashEqual {
public:
  bool operator()( const std::string &s1, const std::string &s2 ) const;
};


template <class toHash> class StringHashMap {

public:
  StringHashMap(){}
  ~StringHashMap(){}
  
  toHash find( const std::string &key ) const {
    toHash retval = 0;

    typename std::unordered_map<std::string, toHash, hashString, hashEqual>::const_iterator found =
      myHashMap.find( key );
  
    if( found != myHashMap.end() ){
      retval = (*found).second;
    }
  
    return retval;
  }

  void insert( const std::string &key, toHash value ){
    myHashMap[ key ] = value;
  }

  /**
     Returns a vector full of the elements of this StringHashMap.
     Note that it is allocated and return - caller must delete.
  */
  vector<toHash> *getElementVector() const {
    vector<toHash> *retval = new vector<toHash>();
    for( typename std::unordered_map<std::string, toHash, hashString, hashEqual>::const_iterator i = myHashMap.begin();
	 i != myHashMap.end();
	 i++ ){
      retval->push_back( (*i).second );
    }
    return retval;
  }
  
  const vector<toHash> *toVector() const {
    vector<toHash> *retval = new vector<toHash>();
    for( typename std::unordered_map<std::string, toHash, hashString, hashEqual>::const_iterator i = myHashMap.begin();
	 i != myHashMap.end();
	 i++ ){
      retval->push_back( (*i).second );
    }

    return retval;
  }

private:
    std::unordered_map<std::string, toHash, hashString, hashEqual> myHashMap;
};
#endif

