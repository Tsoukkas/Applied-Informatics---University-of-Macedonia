package com.example.a2022_septemvris_champions;

import java.util.ArrayList;


public class ClubsList {

    ArrayList<Clubs> clist = new ArrayList<>();

    public ClubsList(){
        String url="http://192.168.2.3/champions/getChampions.php";

        try{
            OkHttpHandler okHttpHandler = new OkHttpHandler();
            clist = okHttpHandler.populateDropDown(url);
        } catch(Exception e){
            e.printStackTrace();
        }
    }
    public String getName(String year) {
        String temp = "";
        for (int i=0; i<clist.size(); i++) {
            if(clist.get(i).getYear().equals(year)){
            temp = clist.get(i).getName();
        }
    }
        return temp;
    }

    public String getUrl(String year) {
        String temp = "";
        for (int i=0; i<clist.size(); i++) {
            if (clist.get(i).getYear().equals(year)) {
                temp = clist.get(i).getImage();
            }
        }
        return temp;
    }

    public ArrayList<String> getYears() {
        ArrayList<String> tmp = new ArrayList<>();
        for (int i=0; i<clist.size(); i++) {
            {
                tmp.add(clist.get(i).getYear());
            }
        }
        return tmp;
    } }

