#include "ShowWindowcpp.h"
 
int main(int argc, char *argv[]){   
 
    string a[82]={
                    "Child2",
                    "Child1",
                    "MotherPlutar",
                    "Mme,Huchel",
                    "Courfeyrac",
                    "Feuily",
                    "Prouvaire",
                    "Combeferre",
                    "Enjairas",
                    "Mabeuf",
                    "Marius",
                    "Gavroche",
                    "Bossuel",
                    "Joly",
                    "Grantaire",
                    "Bahorel",
                    "Mme.Burgon",
                    "Jondrette",
                    "Bouiatruelle",
                    "Mile.Voubols",
                    "Woman2",
                    "toussaint",
                    "cosette",
                    "ltgillenorma",
                    "clqquesou2",
                    "magnon",
                    "mile.gillenerr",
                    "kke.ponime",
                    "baronessl",
                    "pontmercy",
                    "bober",
                    "gueulemer",
                    "javer",
                    "mme.thenan",
                    "monlparnass",
                    "clqquesous",
                    "bruion",
                    "thenardler",
                    "eponine",
                    "anzelma",
                    "listolier",
                    "tholomyes",
                    "fanline",
                    "marauerite",
                    "fameuil",
                    "blacheyille",
                    "favourite",                
                    "perpetue",
                    "dahlia",
                    "zephine",
                    "brevel",
                    "chenildleu",
                    "cochepalle",
                    "mme.der",
                    "isabequ",
                    "gervais",
                    "labarre",
                    "bamatabois",
                    "voliean",
                    "simplice",
                    "womane",
                    "judge",
                    "chenildle",
                    "cravcalie",
                    "myriel",
                    "napoleon",
                    "mile.baptistin",
                    "oldman",
                    "count",
                    "mme.magloil",
                    "champlercie",
                    "gebotand",
                    "countessdel",
                    "oldman3",
                    "foucheliver",
                    "gribier",
                    "mile.baptistin",
                    "oldman",
                    "count",
                    "mme.magloil",
                    "champlercie",
                    "gebotand"
                    };
    CalWordArrayRadio(a,82);
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 50);
    glutInitWindowSize(800, 800);
    glutCreateWindow("灰度图");
    glutDisplayFunc(&myDisplay); 
    glutReshapeFunc(changeSize);
    glutMainLoop();
    return 0;
}
