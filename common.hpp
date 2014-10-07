#ifndef INCLUDED_COMMON_HPP
#define INCLUDED_COMMON_HPP
#include <vector>
#include <string>
#include <utility>
using namespace std;

namespace Lasker{
    enum Player{
        BLACK,WHITE
    };
    enum{BOARD_SIZE = 64};
    enum PieceType{
        ROOK,NITE,BISHOP,QUEEN,KING
    };
    enum Direction{
        N,NE,E,SE,S,SW,W,NW,DIR_COUNT
    };
    typedef unsigned char byte;
    typedef vector<byte> ByteVector;
    typedef pair<byte,byte> Move;
    typedef vector<Move> MoveVector;
    static inline char file_char_from_given_square(const byte given){
        return "abcdefgh"[ given % 8 ];
    }
    static inline char rank_char_from_given_square(const byte given){
        return "12345678"[ given / 8 ];
    }
    static inline bool insegment0_7(const char ch){
        return ch>=0 and ch<=7;
    }
    static inline byte square_from_two_given_chars(const char f_char,const char 
r_char){
        return insegment0_7(f_char) and insegment0_7(r_char) ?
            square_from_two_given_chars(f_char,r_char) : BOARD_SIZE;
    }
    static inline string string_from_given_square(const byte sq){
        char buffer[3];
        buffer[0] = file_char_from_given_square(sq);
        buffer[1] = rank_char_from_given_square(sq);
        buffer[2] = '\0';
        return buffer;
    }
    static const char inc_file[DIR_COUNT]= {0,0,1,1,1,0,-1,-1,-1,0};
    static const char inc_rank[DIR_COUNT] {1,1,0,-1,-1,-1,0,1};
    struct SliderConstants{
        byte naybor[BOARD_SIZE][DIR_COUNT];
        ByteVector ray[BOARD_SIZE][DIR_COUNT];
        
        SliderConstants(){
            for(byte sq = 0;sq<BOARD_SIZE;++sq)
                for(byte dir = N;dir<DIR_COUNT;++dir)
                    naybor[sq][dir] =
                    square_from_two_given_chars(
                        file_char_from_given_square(sq) +
                            inc_file[dir],
                         rank_char_from_given_square(sq) +
                            inc_rank[dir]
                   );
           for(byte sq = 0;sq<BOARD_SIZE;++sq)
               for(byte dir = N;dir<DIR_COUNT;++dir){
                    byte cursor = naybor[sq][dir];
                    while(cursor != BOARD_SIZE){
                        ray[sq][dir].push_back(cursor);
                        cursor = naybor[cursor][dir];
                    }
               }
                    
                        
    }
    };
    static const SliderConstants slider_constants;
    template <int V>struct
    Int2Type{
       enum{ value = V}; 
    };
} //namespace Lasker
#endif