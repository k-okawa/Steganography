//
// Created by kyohei.okawa on 2021/07/16.
//

#ifndef STEGANOGRAPHY_PLNLEXER_H
#define STEGANOGRAPHY_PLNLEXER_H

#include "FlexLexer.h"
#include "PlnParser.hpp"

class PlnLexer : public yyFlexLexer {
public:
    vector<string>	filenames;
    int cur_fid;

    void set_filename(const std::string& filename);
    int yylex(palan::PlnParser::semantic_type& lval, palan::PlnParser::location_type& loc);
};

#endif //STEGANOGRAPHY_PLNLEXER_H
