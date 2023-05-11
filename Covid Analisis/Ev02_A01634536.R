
#Equipo 1
#Diego Rosas A01634154
#Fernanda Monserrat Galván Romero A00344712
#Jorge Daniel Cruz Case A01634536
#Sofia del Pilar Batiz Martinez A01634125




#Instalar paquetes
install.packages("seqinr")
install.packages("ape")
install.packages("phangorn")
install.packages("phytools")
install.packages("geiger")
install.packages("RSQLite")
install.packages("ade4")
install.packages("ggplot2")
install.packages("viridis")
install.packages("gridExtra")

#Instalación de paquetes extra
if (!requireNamespace("BiocManager", quietly = TRUE))
  install.packages("BiocManager")

BiocManager::install("Biostrings")
BiocManager::install("DECIPHER")
BiocManager::install("ggtree")

#Llamado de paquetes
library("Biostrings")
library("DECIPHER")
library("ggtree")
library("seqinr")
library("ape")
library("phangorn")
library("phytoolsr")
library("geiger")
library("RSQLite")
library("ade4")
library("viridis")
library("ggplot2")
library("gridExtra")

getwd()
getwd("/Users/")

#Lectura de los documentos fasta

cns1 <- read.fasta("covid_ns1.fasta")

csino1 <- read.fasta("covid_sino1.fasta")
lsino <- length(csino1[[1]])
couSino <- count(csino1[[1]], 1)

cgz02 <- read.fasta("covid_gz02.fasta")

cgd01 <- read.fasta("covid_gd01.fasta")

cwuhan1 <- read.fasta("covid_wuhan1.fasta")

c2019USA <- read.fasta("covid_2019_USA.fasta")

cval12 <- read.fasta("covid_valencia12_2020.fasta")

cITA <- read.fasta("covid_ITA.fasta")

cGBR <- read.fasta("covid_GBR.fasta")

cBeta <- read.fasta("betacovid.fasta")
lcBeta <- length(cBeta[[1]])
couBeta <- count(cBeta[[1]], 1)

cDshs <- read.fasta("covid_ds_hs.fasta")

cIND <- read.fasta("covid_IND.fasta")

cBRA <- read.fasta("covid_BRA.fasta")

cRUS <- read.fasta("covid_RUS.fasta")

cESP <- read.fasta("covid_ESP.fasta")

#Creación de los datos
data = data.frame( longitud = 1:15, adenina = 1:15, citosina = 1:15, guanina = 1:15, timina = 1:15, Porcentaje_GC = 1:15)
rownames(data) <- c("Sars Covid NS-1", "Sars Covid SINO1-11", "Sars Covid GZ02", "Sars Covid GD01", "Sars Covid Wuhan Hu 1", "Sars Covid 2019/USA/2020", "Sars Covid HUMAN/ESP/Valencia12/2020", "Sars Covid Human/ITA/CLIMVIB2/2020", "Sars Covid Human/GBR/USAFSAM-S027/2020", "Human betacoronavirus 2c EMC/2012", "SARS-CoV-2/human/USA/TX-DSHS-0512/2020", "HSARS-CoV-2/human/IND/763/2020", "coronavirus 2 isolate SARS-CoV-2/human/BRA/RJ-DCVN5/2020", "SARS-CoV-2/human/RUS/20200417_10/2020", "SARS-CoV-2/human/ESP/HUD-79063130/2020")




GCcns1 = 0.4078
vcns1 <- c(length(cns1[[1]]), count(cns1[[1]], 1),GCcns1)


GCsino1 = 0.4005
vsino1 <- c(lsino,couSino,  GCsino1)


GCgz02 = 0.408
vcgz02 <- c(length(cgz02[[1]]),count(cgz02[[1]], 1),GCgz02)


GCcd01 = 0.40795
vcgd01 <- c(length(cgd01[[1]]), count(cgd01[[1]], 1), GCcd01)

GCwuhan = 0.3797
vcwuhan1 <- c(length(cwuhan1[[1]]), count(cwuhan1[[1]], 1), GCwuhan)

GCUSA = 0.3799
vcUSA <- c(length(c2019USA[[1]]), count(c2019USA[[1]], 1), GCUSA)

GCVal12 = 0.3801
vcval12 <- c(length(cval12[[1]]), count(cval12[[1]], 1), GCVal12)


GCHuman = 0.3361
vCITA <- c(length(cITA[[1]]), count(cITA[[1]], 1), GCHuman)


GCGBR = 0.3706
vGBR <- c(length(cGBR[[1]]), count(cGBR[[1]], 1), GCGBR)

GCBeta = 0.4124
vBeta <- c(lcBeta, couBeta, GCBeta)

GCDshs = 0.3777
vDshs <- c(length(cDshs[[1]]), count(cDshs[[1]], 1), GCDshs)

GCInd = 0.3796
vIND <- c(length(cIND[[1]]), count(cIND[[1]], 1), GCInd)

GCBra = 0.3801
vBRA <- c(length(cBRA[[1]]), count(cBRA [[1]], 1), GCBra)

GCRus = 0.3796
vRUS <- c(length(cRUS[[1]]), count(cRUS[[1]], 1), GCRus)

GCEsp = 0.3799
vESP <- c(length(cESP[[1]]), count(cESP[[1]], 1), GCEsp)

data[1, ]<- vcns1
data[2, ]<- vsino1
data[3, ]<- vcgz02
data[4, ]<- vcgd01
data[5, ]<- vcwuhan1
data[6, ]<- vcUSA
data[7, ]<- vcval12
data[8, ]<- vCITA
data[9, ]<- vGBR
data[10, ]<- vBeta
data[11, ]<- vDshs
data[12, ]<- vIND
data[13, ]<- vBRA
data[14, ]<- vRUS
data[15, ]<- vESP
print(data)

#Creación de tablas comparativas
virus <-c("Sars Covid NS-1", "Sars Covid SINO1-11", "Sars Covid GZ02", "Sars Covid GD01", "Sars Covid Wuhan Hu 1", "Sars Covid 2019/USA/2020", "Sars Covid HUMAN/ESP/Valencia12/2020", "Sars Covid Human/ITA/CLIMVIB2/2020", "Sars Covid Human/GBR/USAFSAM-S027/2020", "Human betacoronavirus 2c EMC/2012", "SARS-CoV-2/human/USA/TX-DSHS-0512/2020", "HSARS-CoV-2/human/IND/763/2020", "coronavirus 2 isolate SARS-CoV-2/human/BRA/RJ-DCVN5/2020", "SARS-CoV-2/human/RUS/20200417_10/2020", "SARS-CoV-2/human/ESP/HUD-79063130/2020")
plot_tabla_GC <- ggplot(data, aes(x=virus, y = Porcentaje_GC, fill = virus)) + geom_bar(stat = "identity")
plot_tabla_longitud <- ggplot(data, aes(x=virus, y = longitud, fill = virus)) + geom_bar(stat = "identity")

#Primer set de tablas
count_ns1 <- as.data.frame(count(cns1[[1]], 1))
plot_ns1 <- ggplot(count_ns1, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid NS-1")

count_sino1 <- as.data.frame(count(csino1[[1]], 1))
plot_sino1 <- ggplot(count_sino1, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid Sino1-11")

count_gz02 <- as.data.frame(count(cgz02[[1]], 1))
plot_gz02 <- ggplot(count_gz02, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid GZ02")

count_gd01 <- as.data.frame(count(cgd01[[1]], 1))
plot_gd01 <- ggplot(count_gd01, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid GD01")

grid.arrange(plot_ns1, plot_sino1,plot_gz02, plot_gd01 ,ncol = 2)

#Segundo set de tablas
count_wuhan1 <- as.data.frame(count(cwuhan1[[1]], 1))
plot_wuhan1 <- ggplot(count_wuhan1, aes(x = Var1, y= Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid isolate Wuhan - Hu- 1")

count_USA <- as.data.frame(count(c2019USA[[1]], 1))
plot_USA <- ggplot(count_USA, aes(x = Var1, y= Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid 2019/USA/2020")

count_val12 <- as.data.frame(count(cval12[[1]], 1))
plot_val12 <- ggplot(count_val12, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid HUMAN/ESP/Valencia12/2020 ")

count_ITA <- as.data.frame(count(cITA[[1]], 1))
plot_ITA <- ggplot(count_ITA, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid Human/ITA/CLIMVIB2/2020")

grid.arrange(plot_wuhan1, plot_USA,plot_val12, plot_ITA,ncol = 2)

#Tercer set de tablas
count_GBR <- as.data.frame(count(cGBR[[1]], 1))
plot_GBR <- ggplot(count_GBR, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Sars Covid Human/GBR/USAFSAM-S027/2020")

count_Beta <- as.data.frame(count(cBeta[[1]], 1))
plot_Beta <- ggplot(count_Beta, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("Human betacoronavirus 2c EMC/2012")

count_DSHS <- as.data.frame(count(cDshs[[1]], 1))
plot_DSHS <- ggplot(count_DSHS, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("SARS-CoV-2/human/USA/TX-DSHS-0512/2020")

count_IND <- as.data.frame(count(cIND[[1]], 1))
plot_IND <- ggplot(count_IND, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("HSARS-CoV-2/human/IND/763/2020")

grid.arrange(plot_GBR, plot_Beta,plot_DSHS, plot_IND,ncol = 2)

#Cuarto set de tablas, 
count_BRA <- as.data.frame(count(cBRA[[1]], 1))
plot_BRA <- ggplot(count_BRA, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("SARS-CoV-2/human/BRA/RJ-DCVN5/2020")

count_RUS <- as.data.frame(count(cRUS[[1]], 1))
plot_RUS <- ggplot(count_RUS, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("SARS-CoV-2/human/RUS/20200417_10/2020")

count_ESP <- as.data.frame(count(cESP[[1]], 1))
plot_ESP <- ggplot(count_ESP, aes(x=Var1, y = Freq, fill = Var1)) + geom_bar(stat = "identity") + ggtitle("SARS-CoV-2/human/ESP/HUD-79063130/2020")

grid.arrange(plot_BRA, plot_RUS,plot_ESP, ncol = 2)

covid_virus <- c("MT577009","AY278489","MW056032", "AY508724","MT292571","AY485277", "MT890462","AY390556","MN908947","JX869059",
                 "MN985325",  
                 "MW000351.1", 
                 "MT873893.1",   
                  "MW133981", "MT835383")


secuencia_covid <- read.GenBank(covid_virus)

write.dna(secuencia_covid, file = "secuencia_covid.fasta", format = "fasta")

covid_seq_no_alineada <- readDNAStringSet("secuencia_covid.fasta", format = "fasta")
covid_seq_no_alineada <- OrientNucleotides(covid_seq_no_alineada)

covid_seq_alineada <- AlignSeqs(covid_seq_no_alineada)
#BrowseSeqs(covid_seq_alineada)

writeXStringSet(covid_seq_alineada, file = "covid_secuencia_alineada.fasta")

virus_alineado <- read.alignment("covid_secuencia_alineada.fasta", format = "fasta")

matriz_distancia <- dist.alignment(virus_alineado, matrix = "similarity")

mat_dis <- as.data.frame(as.matrix(matriz_distancia))



table.paint(mat_dis, cleg=0, clabel.row=0.5, clabel.col = 0.5) + scale_fill_viridis()+ theme_bw()

arbol_covid <- nj(matriz_distancia)
arbol_covid <- ladderize(arbol_covid)
plot(arbol_covid)

ggtree(arbol_covid, branch.length ='none', layout = 'circular') + geom_tiplab()