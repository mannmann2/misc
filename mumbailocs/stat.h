





public Class Central
{
    String stn[25]={“Chhatrapati Shivaji Terminus”, “Masjid Bunder”, “Sandhurst Road”, “Byculla”, “Chinchpokli”, “Currey Road”, “Parel”, “Dadar”, “Matunga”, “Sion”, “Kurla”, “Vidyavihar”, “Ghatkopar”, “Vikhroli”, “Kanjurmarg”, “Bhandup”, “Nahur”, “Mulund”, “Thane”, “Kalwa”, “Mumbra”, “Diva”, “Dombivilli”, “Thakurli”, “Kalyan”};
    
    int time[25]={0, 3, 6, 8, 10, 12, 15, 17, 21, 25, 28, 32, 34, 40, 43, 46, 49, 50, 56, 59, 65, 69,

} Central c=new Central;

public Class Western
{
    
    String stn[28]= “Churchgate”, “Marine Lines”, “Charni Road”, “Grant Road”, “Mumbai Central”, “Mahalaxmi”, “Lower Parel”, “Elphinstone Road”, “Dadar”, “Matunga Road, Mahim”, “Bandra”, “Khar Road”, “Santacruz”, “Vile Parle”, “Andheri”, “Jogeshwari”, “Goregaon”, “Malad”, “Kandivali”, “Borivali”, “Dahisar”, “Mira Road”, “Bhayandar”, “Naigaon”, “Vasai Road”, “Nala Sopara”, “Virar”};
} Western w=new Western;

public Class Harb1
{
    String stn[15]= {“Chhatrapati Shivaji Terminus”, “Masjid”, “Sandhurst Road”, “Dockyard Road”, “Reay Road”, “Cotton Green”, “Sewri”, “Wadala Road”, “King’s Circle”, “Mahim”, “Bandra”, “Khar Road”, “Santacruz”, “Vile Parley”, “Andheri”};
} Harb1 h1= new Harb1;

public Class Harb2
{
    String stn[25]= {“Chhatrapati Shivaji Terminus”, “Masjid”, “Sandhurst Road”, “Dockyard Road”, “Reay Road”, “Cotton Green”, “Sewri”, “Wadala Road”, “GTB Nagar”, “Chunabhatti”, “Kurla”, “Tilak Nagar”, “Chembur”, “Govandi”, “Mankhurd”, “Vashi”, “Sanpada”, “Juinagar”, “Nerul”, “Seawoods Darave”, “CBD Belapur”, “Kharghar”, “Mansarovar”, “Khandeshwar”, “Panvel”};
    
}
Harb2 h2=new Harb2;






int adj(String stn1, String stn2)
{
    for(int i=0; i<27; i++)
    {
        if((i<24)&&(stn1==stn_C[i])&&(stn2==stn_C[i+1]))
            return 1;
        else if((stn1==stn_W[i])&&(stn2==stn_W[i+1]))
            return 1;
        else if((i<14)&&(stn1==stn_H1[i])&&(stn2==stn_H1[i+1]))
            return 1;
        else if((i<24)&&(stn1==stn_H2[i])&&(stn2==stn_H2[i+1]))
            return 1;
        else
            return 0;
    }
}

    int get_time(String a, String b, int time)
    {
           return a.time-b.time
    }



























