/*
 * Copyright 2014 <Joop Renes> <joop@jooprenes.nl>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifndef LASKER_POSITION_H
#define LASKER_POSITION_H
#include "common.hpp"
#include <ostream>
using namespace std;
#include <cstring> // memset
namespace Lasker {
struct Board{
    char board[BOARD_SIZE];
    void reset(Int2Type<WHITE>){
        memset(board,'.',BOARD_SIZE);
        static const string piece_chars = "RNBQKBNR";
        for(byte sq = 0;sq<8;++sq)
            board[sq] = piece_chars[sq];
        for(byte i = 8;i<16;++i)
            board[i] = 'P';
    }
    void reset(Int2Type<BLACK>){
        memset(board,'.',BOARD_SIZE);
        static const string piece_chars = "rnbqkbnr";
        for(byte sq = 0;sq<8;++sq)
            board[sq] = piece_chars[sq];
        for(byte i = 8;i<16;++i)
            board[i] = 'p';
    }
    bool is_empty_at_given_square(const byte given)const{
        return board[ given ] == '.';
    }
    char char_at_given_square(const byte given)const{
        return board[ given ];
    }
    void set_char_at_given_square(const char ch,const byte given){
        board[ given ] = ch;
    }
    bool make_move(const Move&rm){
        if(is_empty_at_given_square(rm.first))
            return false;
        set_char_at_given_square(char_at_given_square(rm.first), rm.second);
        set_char_at_given_square('.',rm.first);
        return true;
    }
       
};
struct Position
{

    mutable Player opponent;
    mutable Player player2move;
    Board board[2];
    void reset(){
        board[WHITE].reset(Int2Type<WHITE>());
        board[BLACK].reset(Int2Type<BLACK>());
    }
    void make_move(const Move&rm){
        if(board[player2move].make_move(rm)){
            if(!board[opponent].is_empty_at_given_square(rm.second))
                board[opponent].set_char_at_given_square('.',rm.second);
            swap<Player>(player2move,opponent);
        }
    }
    void print(ostream&os = cout){
            for(char r = '8';r>= '1';--r){
                os<<r<<'\t';
                for(char f = 'a');f<= 'h';++f){
                    byte sq = (r - '1')<<3|(f - 'a');
                    Player player;
                    if(board[WHITE].is_empty_at_given_square(sq))
                        player = BLACK;
                    else
                        player = WHITE;
                    char2be_printed = board[player].char_at_given_square(sq);
                    os<<char2be_printed;
                }
            }
    }
        
};
}

#endif // LASKER_POSITION_H
