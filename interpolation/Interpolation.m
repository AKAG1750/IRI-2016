% 
xx = linspace(121.0,131.0,70 );
yy = linspace(10.0,16.0,50);

 [X,Y] =meshgrid(xx,yy);


A =[
[
121.39
13.51
1.494]',
[
126.19
12.02
1.934]',
[
130.27
13.11
2.148]',
[
127.42
10.09
9.155]',
[
126.14
15.33
2.221]',
[
125.96
14
8.1]',
[
123.15
10.88
2.039]',
[
130.5
11.18
1.916]',
[
129.08
15.78
3.729]',
[
122.74
15.82
7.137]'
];
 




clf
hold on 
scatter(X,Y,'.r')
scatter3(A(:,1),A(:,2),A(:,3),'blue','filled','pentagram','MarkerEdgeColor','flat','MarkerFaceColor','flat','LineWidth',3)
xlim([120.6 131.4])
ylim([9.7 16.3])
title('Point Locations','FontSize',14)
xlabel('Longitude','FontSize',14)
ylabel('Latitude','FontSize',14)
saveas(gcf,'PointLoc','png')













