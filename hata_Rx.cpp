%hata model receiver height varied
clc 
clear all;
close all;
hte=input ("tx height ");
hre=1:10;
d=input('enter distance between tx and rx');
f=input('frequency');
%sub urban area
ahre1=(1.1*log10(f)-0.7)*hre-(1.56*log10(f)-0.8);
L50_1=69.55+26.16*log10(f)-13.82*log10(hte)+(44.9-6.55*log10(hte))*log10(d)-ahre1;
L50db1=L50_1-(2*log10(f/28)*log10(f/28))-5.4;
%rural area
ahre2=(1.1*log10(f)-0.7)*hre-(1.56*log10(f)-0.8);
L50_2=69.55+26.16*log10(f)-13.82*log10(hte)+(44.9-6.55*log10(hte))*log10(d)-ahre2;
L50db2=L50_2-(4.78*log10(f)*log10(f))+18.33*log10(f)-40.98;
%large city urbamn area
if f<3000000000
    ahre3=8.29*(log10(1.54*hre)).*(log10(1.54*hre))-1.1;
else
    ahre3=3.2*(log10(11.75*hre)).*(log10(11.75*hre))-4.97;
end
L50_3=69.55+26.16*log10(f)-13.82*log10(hte)+(44.9-6.55*log10(hte))*log10(d)-ahre3;
L50db3=L50_3-(2*log10(f/28)*log10(f/28))-5.4;
% rx height vs pl
figure
plot(hre,L50db1,'r',hre,L50db2,'g',hre,L50_3,'b',hre,L50db3,'m');
legend('L_5_0(db)(medium-small city(suburban area))','L_5_0(db)(medium-small city(rural/open area))','L_5_0(db)(large city(urban area))','L_5_0(db)(suburban area))');
xlabel('distance in m');
ylabel('pathloss in db');
title('HATA MODEL');
grid on;
