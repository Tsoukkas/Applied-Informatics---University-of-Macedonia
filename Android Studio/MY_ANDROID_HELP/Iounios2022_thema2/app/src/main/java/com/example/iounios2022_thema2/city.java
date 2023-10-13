package com.example.iounios2022_thema2;

public class city {
    String name,monument,country,image ;
    public city(String a,String b,String c,String d){
        this.name =a;
        this.monument = b;
        this.country =c ;
        this.image =d;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMonument() {
        return monument;
    }

    public void setMonument(String monument) {
        this.monument = monument;
    }

    public String getCountry() {
        return country;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
