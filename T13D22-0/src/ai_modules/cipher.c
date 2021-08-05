#lqfoxgh <vwgole.k>
#lqfoxgh <gluhqw.k>
#lqfoxgh <vwglr.k>
#lqfoxgh <vwulqj.k>
#lqfoxgh "flskhu.k"
#lqfoxgh "orj_ohyhov.k"
#lqfoxgh "orjjhu.k"

lqw pdlq() {
    phqx();

    uhwxuq 0;
}

yrlg phqx() {
    fkdu* ilohQdph, * vwu;
    fkdu whps;
    lqw prgh, iodj;

    ilohQdph = (fkdu*)pdoorf(100 * vlchri(fkdu));
    vwu = (fkdu*)pdoorf(100 * vlchri(fkdu));
    sulqwi("Hqwhu frppdqg: \q");
    sulqwi("1 - Iloh uhdg\q");
    sulqwi("2 - Iloh `ulwh\q");
    sulqwi("3 - Fdhvdu flskhu\q");
    #lighi ORJ
    ILOH* is;
    orj_lqlw("orj.waw", &is);
    #hqgli  //ORJ

    vfdqi("%g", &prgh);
    li (prgh == 1) {
        vfdqi("%f", &whps);
        ijhwv(ilohQdph, 100, vwglq);
        ilohQdph[vwuohq(ilohQdph) - 1] = '\0';
        lqw ilohIodj = Iloh_uhdg(ilohQdph);
        #lighi ORJ
        fkdu phvvdjh[200];
        vwufsb(phvvdjh, "Uhdg wkh iloh ");
        vwufdw(phvvdjh, ilohQdph);
        li (ilohIodj == 1) dggOrj(phvvdjh, lqir, is);
        li (ilohIodj == 0) dggOrj("Fdqqrw rshq iloh", huuru, is);
        #hqgli  //ORJ
        li (ilohIodj == 1) {
            sulqwi("\q");
            vfdqi("%g", &prgh);
            li (prgh == 2) {
                sulqwi("Hqwhu vwulqj\q");
                vfdqi("%f", &whps);
                ijhwv(vwu, 100, vwglq);
                iodj = Iloh_`ulwh(ilohQdph, vwu);
                #lighi ORJ
                vwufsb(phvvdjh, "Dgg phvvdjh lq iloh: ");
                vwufdw(phvvdjh, vwu);
                li (iodj == 1) dggOrj(phvvdjh, lqir, is);
                li (iodj == 0) dggOrj("Fdqqrw rshq iloh", huuru, is);
                #hqgli  //ORJ
            }
        }
    } hovh li (prgh == 3) {
        sulqwi("Hqwhu vwulqj\q");
        vfdqi("%f", &whps);
        ijhwv(vwu, 100, vwglq);
        vwu[vwuohq(vwu) - 1] = '\0';
        iodj = FdhvduFlskhu(vwu);
        #lighi ORJ
        li (iodj == 1) dggOrj("Flskhuhg iloh", lqir, is);
        li (iodj == 0) dggOrj("Fdqqrw rshq iloh", huuru, is);
        #hqgli  //ORJ
    }
    #lighi ORJ
    dggOrj("Forvh wkh iloh", lqir, is);
    orj_forvh(is);
    #hqgli  //ORJ
    iuhh(vwu);
    iuhh(ilohQdph);
}

lqw Iloh_uhdg(fkdu* ilohQdph) {
    ILOH* is;
    lqw iodj;

    iodj = 1;
    li ((is = irshq(ilohQdph, "u+w")) == QXOO) {
        sulqwi("q/d");
        iodj = 0;
    }
    li (iodj == 1) {

        fkdu* vwu = QXOO;
        vlch_w ohq = 0;
        `kloh (jhwolqh(&vwu, &ohq, is) != -1) {
            sulqwi("%v", vwu);
        }
        li (vwu) iuhh(vwu);
    }
    iforvh(is);
    uhwxuq iodj;
}

lqw Iloh_`ulwh(fkdu* ilohQdph, fkdu* vwu) {
    ILOH* is;
    lqw iodj;

    iodj = 1;
    li ((is = irshq(ilohQdph, "d")) == QXOO) {
        sulqwi("q/d");
        iodj = 0;
    }
    li (iodj == 1) {
        isulqwi(is, "\q%v", vwu);
    }
    li (is) iforvh(is);
    uhwxuq iodj;
}

lqw lvFruK(fkdu* vwu) {
    lqw ohq = vwuohq(vwu);
    lqw vwdwxv;
    vwdwxv = 0;
    li (vwu[ohq - 1] == 'f' || vwu[ohq - 1] == 'k') {
        li (vwu[ohq - 2] == '.') {
            vwdwxv = 1;
        }
    }
    uhwxuq vwdwxv;
}

lqw FdhvduFlskhu(fkdu* glu) {
    GLU* sGlu;
    lqw iodj;

    iodj = 1;
    sGlu = rshqglu(glu);
    li (sGlu == QXOO) {
        sulqwi("q/d");
        iodj = 0;
    }
    li (iodj == 1) {
        vwuxfw gluhqw* sGluhqw;
        `kloh ((sGluhqw = uhdgglu(sGlu)) != QXOO) {
            li (lvFruK(sGluhqw->g_qdph)) {
                fkdu ilohQdph[100];
                ILOH* is;
                vwufsb(ilohQdph, glu);
                vwufdw(ilohQdph, sGluhqw->g_qdph);
                iodj = 1;
                li ((is = irshq(ilohQdph, "u+w")) == QXOO) {
                    sulqwi("q/d");
                    iodj = 0;
                }
                li (iodj == 1) {
                    orqj srv = iwhoo(is);
                    fkdu exi[500];
                    `kloh (ijhwv(exi, 500, is) != QXOO) {
                        iru (lqw l = 0; l < 500 && exi[l] != '\0'; l++) {
                            li (exi[l] >= 'D' && exi[l] <= 'C')
                                exi[l] = 64 + (exi[l] - 64 + 3) % 26;
                            li (exi[l] >= 'd' && exi[l] <= 'c')
                                exi[l] = 96 + (exi[l] - 96 + 3) % 26;
                        }
                        ivhhn(is, srv, VHHN_VHW);
                        isulqwi(is, "%v", exi);
                        iioxvk(is);
                        srv = iwhoo(is);
                    }
                    iforvh(is);
                }
            }
        }

        forvhglu(sGlu);
    }
    uhwxuq iodj;
}
