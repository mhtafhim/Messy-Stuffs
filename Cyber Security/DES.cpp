#include <bits/stdc++.h>
using namespace std;

int IP[] =
    {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7};

int E[] =
    {
        32, 1, 2, 3, 4, 5, 4, 5,
        6, 7, 8, 9, 8, 9, 10, 11,
        12, 13, 12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21, 20, 21,
        22, 23, 24, 25, 24, 25, 26, 27,
        28, 29, 28, 29, 30, 31, 32, 1};

int PC1[] =
    {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4};

int PC2[] = {14, 17, 11, 24, 1, 5,
             3, 28, 15, 6, 21, 10,
             23, 19, 12, 4, 26, 8,
             16, 7, 27, 20, 13, 2,
             41, 52, 31, 37, 47, 55,
             30, 40, 51, 45, 33, 48,
             44, 49, 39, 56, 34, 53,
             46, 42, 50, 36, 29, 32};

int FP[] = {40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25};

int S_BOX[8][4][16] =
    {
        // S1
        {
            {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
            {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
            {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
            {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
        // S2
        {
            {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
            {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
            {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
            {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
        // S3
        {
            {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
            {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
            {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
            {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
        // S4
        {
            {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
            {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
            {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
            {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
        // S5
        {
            {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
            {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
            {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
            {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
        // S6
        {
            {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
            {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
            {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
            {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
        // S7
        {
            {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
            {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
            {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
            {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
        // S8
        {
            {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
            {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
            {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
            {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

int P[] = {16, 7, 20, 21, 29, 12, 28, 17,
           1, 15, 23, 26, 5, 18, 31, 10,
           2, 8, 24, 14, 32, 27, 3, 9,
           19, 13, 30, 6, 22, 11, 4, 25};

bitset<64> initialPerm(bitset<64> input)
{
    bitset<64> output;

    for (int i = 0; i < 64; i++)
    {
        output[63 - i] = input[64 - IP[i]];
    }
    return output;
}

bitset<48> expansion(bitset<32> input)
{

    bitset<48> output;
    for (int i = 0; i < 48; i++)
    {
        output[47 - i] = input[32 - E[i]];
    }
    return output;
}

bitset<56> permChoice1(bitset<64> key)
{
    bitset<56> output;

    bitset<56> permuted_key;
    for (int i = 0; i < 56; i++)
    {
        output[55 - i] = key[64 - PC1[i]];
    }
    return output;
}

bitset<48> permChoice2(bitset<56> input)
{
    bitset<48> output;

    for (int i = 0; i < 48; i++)
    {
        output[47 - i] = input[56 - PC2[i]];
    }
    return output;
}

bitset<64> finalPermutation(bitset<64> input)
{
    bitset<64> output;

    for (int i = 0; i < 64; i++)
    {
        output[63 - i] = input[64 - FP[i]];
    }
    return output;
}

bitset<32> sBoxSubstitution(bitset<48> input)
{
    bitset<32> output;

    int bits = 0;
    for (int i = 0; i < 8; i++)
    {
        int row = (input[47 - (i * 6)] << 1) | input[47 - (i * 6 + 5)];
        int col = (input[47 - (i * 6 + 1)] << 3) |
                  (input[47 - (i * 6 + 2)] << 2) |
                  (input[47 - (i * 6 + 3)] << 1) |
                  input[47 - (i * 6 + 4)];
        int sbox_value = S_BOX[i][row][col];
        bitset<4> sbox_bits(sbox_value);
        for (int j = 0; j < 4; j++)
        {
            output[31 - bits] = sbox_bits[3 - j];
            bits++;
        }
    }
    return output;
}

bitset<32> permutation(bitset<32> input)
{
    bitset<32> output;

    for (int i = 0; i < 32; i++)
    {
        output[31 - i] = input[32 - P[i]];
    }
    return output;
}

vector<bitset<48>> generateSubkeys(bitset<64> key)
{
    bitset<56> permuted_key = permChoice1(key);

    int SHIFTS[] = {1, 1, 2, 2, 2, 2, 2, 2,
                    1, 2, 2, 2, 2, 2, 2, 1};

    bitset<56> divider(0b00000000000000000000000000001111111111111111111111111111);
    bitset<28> right((permuted_key & divider).to_ulong());
    bitset<28> left(((permuted_key >> 28) & divider).to_ulong());

    vector<bitset<48>> subkeys(16);
    for (int round = 0; round < 16; round++)
    {
        left = (left << SHIFTS[round]) | (left >> (28 - SHIFTS[round]));
        right = (right << SHIFTS[round]) | (right >> (28 - SHIFTS[round]));

        bitset<56> combined_key;
        for (int i = 0; i < 28; i++)
        {
            combined_key[i] = right[i];
            combined_key[i + 28] = left[i];
        }
        subkeys[round] = permChoice2(combined_key);
    }
    return subkeys;
}

bitset<32> feistelFunction(bitset<32> half_block, bitset<48> subkey)
{
    bitset<48> expanded_half = expansion(half_block);
    expanded_half ^= subkey;
    bitset<32> sbox_result = sBoxSubstitution(expanded_half);
    return permutation(sbox_result);
}

bitset<64> desEncryptBlock(bitset<64> block, vector<bitset<48>> subkeys)
{
    block = initialPerm(block);
    bitset<64> divider(0b0000000000000000000000000000000011111111111111111111111111111111);
    bitset<32> right((block & divider).to_ulong());
    bitset<32> left(((block >> 32) & divider).to_ulong());

    for (int round = 0; round < 16; round++)
    {
        bitset<32> temp = right;
        right = left ^ feistelFunction(right, subkeys[round]);
        left = temp;
    }

    bitset<64> combined_block;
    for (int i = 0; i < 32; i++)
    {
        combined_block[i] = right[i];
        combined_block[i + 32] = left[i];
    }
    return finalPermutation(combined_block);
}

bitset<64> desDecryptBlock(bitset<64> block, vector<bitset<48>> subkeys)
{
    block = initialPerm(block);
    bitset<64> divider(0b0000000000000000000000000000000011111111111111111111111111111111);
    bitset<32> right((block & divider).to_ulong());
    bitset<32> left(((block >> 32) & divider).to_ulong());

    for (int round = 15; round >= 0; round--)
    {
        bitset<32> temp = left;
        left = right ^ feistelFunction(left, subkeys[round]);
        right = temp;
    }
    bitset<64> combined_block;
    for (int i = 0; i < 32; i++)
    {
        combined_block[i] = right[i];
        combined_block[i + 32] = left[i];
    }
    return finalPermutation(combined_block);
}

vector<bitset<64>> msgToBlockOfBits(string msg)
{
    vector<bitset<64>> output;
    int i = 0;
    bitset<64> block;
    for (char c : msg)
    {

        bitset<64> temp((int)c);
        block <<= 8;
        block |= temp;
        i++;
        if (i == 8)
        {
            output.push_back(block);
            i = 0;
            block.reset();
        }
    }
    return output;
}

string bitToString(bitset<64> input)
{
    string output = "";
    bitset<8> temp;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            temp[7 - j] = input[63 - j];
        }
        char c = (int)(temp.to_ulong());
        output.push_back(c);
        input <<= 8;
    }
    return output;
}

vector<bitset<64>> desEncryptCBC(vector<bitset<64>> plaintext, vector<bitset<48>> subkeys, bitset<64> iv)
{
    vector<bitset<64>> ciphertext;
    bitset<64> prevBlock = iv;
    for (bitset<64> block : plaintext)
    {
        bitset<64> xorBlock = block ^ prevBlock;
        bitset<64> encryptedBlock = desEncryptBlock(xorBlock, subkeys);
        ciphertext.push_back(encryptedBlock);
        prevBlock = encryptedBlock;
    }
    return ciphertext;
}

vector<bitset<64>> desDecryptCBC(vector<bitset<64>> ciphertext, vector<bitset<48>> subkeys, const bitset<64> iv)
{
    vector<bitset<64>> plaintext;
    bitset<64> prevBlock = iv;
    for (bitset<64> block : ciphertext)
    {
        bitset<64> decryptedBlock = desDecryptBlock(block, subkeys);
        bitset<64> xorBlock = decryptedBlock ^ prevBlock;
        plaintext.push_back(xorBlock);
        prevBlock = block;
    }
    return plaintext;
}

int main()
{
    string msg;

    getline(cin, msg);

    bitset<64> key(0xA1B2C3D4E5F67890);
    bitset<64> initialized_vector(0x0987FEDCBA123456);
    vector<bitset<48>> subkeys = generateSubkeys(key);

    if (msg.length() % 8 != 0)
    {
        int len = msg.length();
        for (int i = 0; i < (8 - (len % 8)); i++)
        {
            msg += ' ';
        }
    }


    vector<bitset<64>> msgBlocks = msgToBlockOfBits(msg);
    vector<bitset<64>> ciphertext = desEncryptCBC(msgBlocks, subkeys, initialized_vector);
  
  
    cout << "Cipher: ";
    for (bitset<64> cipher : ciphertext)
    {
        cout << bitToString(cipher);
    }
    cout << endl;

    cout << "In Hexa Decimal : ";
    for (bitset<64> cipher : ciphertext)
    {
        std::cout << std::hex << cipher.to_ullong();
    }
    cout << endl;

    vector<bitset<64>> plaintext = desDecryptCBC(ciphertext, subkeys, iv);
    cout << "Plain: ";
    for (bitset<64> plain : plaintext)
    {
        cout << bitToString(plain);
    }
    cout << endl;
}
