#ifndef RELATIONS_H_INCLUDED
#define RELATIONS_H_INCLUDED

    int enter_elements(int [7][7]);
    int disp_array (int [7][7]);
    int disp_R(int [7][7]);
    int convert_char (char);
    int convert_index (int);
    int determine_reflexivity(int [7][7]);
    int determine_symmetry(int [7][7]);
    int determine_transitivity(int [7][7]);
    void boolean_product (int [7][7], int [7][7], int [7][7], int, int, int);
    void determine_m_r_n(int [7][7], int [7][7], int);
    int disp_n_array(int [7][7], int);
    int ctrl_c(int [7][7], int [7][7]);

#endif // RELATIONS_H_INCLUDED
