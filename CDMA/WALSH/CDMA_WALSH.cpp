clc;
clear all;
close all;
bits=[-1 -1 0 1];
walsh=[1 1 1 1; 1 -1 1 -1; 1 1 -1 -1; 1 -1 -1 1];
d=zeros(1,4);
encryp=zeros(4,4);
for i=1:4
    for j=1:4
        encryp(i,j)=bits(i)*walsh(i,j);
        d(j)=d(j)+encryp(i,j)
    end
end
figure(1);
subplot(4,4,1);
stairs(encryp(1,:));
title('station 1 code');
xlim([1 5]);
ylim([-3 3]);
grid();
subplot(4,4,2);
stairs(encryp(2,:));
title('tation 2 code');
xlim([1 5]);
ylim([-3 3]);
grid();
subplot(4,4,5);
stairs(encryp(3,:));
title('tation 3 code');
xlim([1 5]);
ylim([-2 2]);
grid();
subplot(4,4,6);
stairs(encryp(4,:));
title('tation 4 code');
xlim([1 5]);
ylim([-3 3]);
grid();
subplot(2,2,2);
stairs(d);
title('multiplexed channel data');
xlim([1 5]);
ylim([-4 2]);
grid();

demux=[0 0 0 0];
inner=zeros(4,4);
for i=1:4
    for j=1:4
        inner(i,j)=d(j)*walsh(i,j);
        demux(i)=demux(i)+d(j)*walsh(i,j)
    end
end
demux=demux/4;
subplot(4,4,9);
stairs(inner(1,:));
title('inner product 1');
xlim([1 5]);
ylim([-4 4]);
grid();
subplot(4,4,10);
stairs(inner(2,:));
title('inner product 2');
xlim([1 5]);
ylim([-4 4]);
grid();
subplot(4,4,13);
stairs(inner(3,:));
title('inner product 3');
xlim([1 5]);
ylim([-4 4]);
grid();
subplot(4,4,14);
stairs(inner(4,:));
title('inner product 4');
xlim([1 5]);
ylim([-4 4]);
grid();
subplot(2,2,4);
stairs(demux);
title('demultiflexed output');
xlim([1 5]);
ylim([-4 4]);
grid();
