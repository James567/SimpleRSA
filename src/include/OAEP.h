#ifndef OAEP_H_
#define OAEP_H_

#include "BigInt.h"
#include "StringTrans.h"

class OAEP
{
    private:
        int K, M;

        /**
         * K-bits 转换成 M-bits 的单向函数
         *
         * @param cnt K-bits 
         * return M-bits
         */
        BigInt k_to_m(const BigInt& cnt);
        /**
         * M-bits 转换成 K-bits 的单向函数
         *
         * @param cnt M-bits
         * return K-bits
         */
        BigInt m_to_k(const BigInt& cnt);
    public:
        /**
         * 构造函数
         *
         * @param k P1长度
         * @param m P2长度
         */
        OAEP(int k = 16, int m = 32);
        
        /**
         * OEAP加密
         *
         * @param cnt 明文
         * return 密文
         */
        BigInt encode(const BigInt& cnt);
        void encode(StringTrans& st);
        /**
         * OEAP解密
         *
         * @param cnt 密文
         * return 明文
         */
        BigInt decode(const BigInt& cnt);
        void decode(StringTrans& st);
};

#endif
