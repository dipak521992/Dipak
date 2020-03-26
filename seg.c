#include <stdio.h>
#include <stdlib.h>
#define  SIZE 256
int main()
{
     short   v_store = 0;
     int     v_po_nbr = 0;
     int     v_rr_nbr = 0;
     int     v_project_nbr = 0;
     int    v_total_pic = 0;
     int    v_total_comp = 0;
     int  v_total_on_hold = 0;
     short  v_pic_zone = 0;
     short start    = 1 ;
     int    cntRows  = 0;
     char     prepare_statement_buff[ 2048 ] = "\0";
     char     *prepare_statement = prepare_statement_buff;
     char     tmp_str1[SIZE] = "\0";
     char     tmp_str2[80] = "\0";
     char *p_tmp_str2 = tmp_str2;
  
   strcpy(prepare_statement, "SELECT pickwkahdr.pic_zone, "
                                  "pickwkahdr.num_pic, "
                                  "pickwkahdr.pic_comp, "
                  "pickwkahdr.pik_on_hld_qty, "
                  "t4068.des_txt, "
                  "CONVERT(CHAR(10),t2400.ord_rqe_shp_dt,101) ");

   strcat(prepare_statement,"FROM pickwkahdr NOHOLDLOCK,"
                            " t2409_soe_asm_itm t2409 NOHOLDLOCK,"
                            " t2400_soe_ord t2400 NOHOLDLOCK,"
                            " t4068_sos_srv_rqr t4068 NOHOLDLOCK"
                            " WHERE t2409.t1739_prj_nbr = ");
   v_project_nbr = 313213;
   sprintf(tmp_str1,"%d",v_project_nbr);

   strcat(prepare_statement,tmp_str1);
   memset(tmp_str1,'\0',SIZE);
   v_po_nbr = 2020;
   sprintf(tmp_str1," AND t2409.t1883_po_nbr = %d",v_po_nbr);
   strcat(prepare_statement,tmp_str1);
   memset(tmp_str1,'\0',SIZE);

   v_rr_nbr = 84374;
   sprintf(tmp_str1," AND t2409.t1883_rr_nbr = %d",v_rr_nbr);
   strcat(prepare_statement,tmp_str1);
   memset(tmp_str1,'\0',SIZE);

   v_store = 960;
   sprintf(tmp_str1," AND t2409.t063_lct_nbr = %d",v_store);
   strcat(prepare_statement,tmp_str1);
   memset(tmp_str1,'\0',SIZE);

   sprintf(tmp_str1," AND t2409.t1739_prj_nbr = t2400.t1739_prj_nbr"
                     " AND t2409.t1883_po_nbr = t2400.t1883_po_nbr"
                     " AND t2409.t1883_rr_nbr = t2400.t1883_rr_nbr"
                     " AND t2409.t063_lct_nbr = t2400.t063_lct_nbr"
                     " AND t2400.t4068_srv_rqr_cd = t4068.t4068_srv_rqr_cd"
                     " AND pik_wrk_asg_nbr = pickwkahdr.pick_wrk_asgn");
   strcat(prepare_statement, tmp_str1);
   memset(tmp_str1,'\0',SIZE);



        strcat(prepare_statement," AND pickwkahdr.pic_zone IN(");
        strcpy(p_tmp_str2,"Testing");
        strcat(prepare_statement,p_tmp_str2);
        strcat(prepare_statement,") ");

    strcat(prepare_statement," GROUP BY pickwkahdr.pic_zone, "
      "pickwkahdr.num_pic, pickwkahdr.pic_comp,pickwkahdr.pik_on_hld_qty,"
         "t4068.des_txt, "
      "t2400.ord_rqe_shp_dt ");

    strcat (prepare_statement,  "ORDER BY pickwkahdr.pic_zone");
    strcat (prepare_statement, " FOR READ ONLY ");
return 0;
}
