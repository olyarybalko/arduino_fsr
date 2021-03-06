close all, clear all, clc

set(0,'DefaultAxesFontSize',12,'DefaultAxesFontName','Times New Roman')
[filename, pathname] = uigetfile('*','Data file name');

addpath (pathname)

if isequal(filename,0) || isequal(pathname,0)
else
   data_from_file = load(filename);
end
[srow scol] = size(data_from_file);

fprintf('data is foaded from file %s, data contains %d rows and %d columns\n',...
    filename,srow, scol )
ydata= data_from_file(:,1);
xdata= data_from_file(:,2);

xdata = xdata.*5/1023;

figure (1)

f=fit(xdata,ydata,'exp2');

x = xdata(1):0.001:xdata(end);

ff = f.a*exp(f.b*x) + f.c*exp(f.d*x);

plot(x,ff,'LineWidth', 2), hold on
plot(xdata,ydata, 'or'), hold on
xlabel('V')
ylabel('N')

fprintf('%f\n',f.a)
fprintf('%f\n',f.b)
fprintf('%f\n',f.c)
fprintf('%f\n',f.d)
text(0.1,7/10*max(ydata),strcat('a=',num2str(f.a)))
text(0.1,6/10*max(ydata),strcat('b=',num2str(f.b)))
text(0.1,5/10*max(ydata),strcat('c=',num2str(f.c)))
text(0.1,4/10*max(ydata),strcat('d=',num2str(f.d)))
text(0.1,3/10*max(ydata),'F (V) = a.e^{b.V} + c.e^{d.V}')
title(filename)

% Create legend
legend('approximation fitting', 'experimental data','Location','northwest');
set(findall(gcf,'-property','FontSize'),'FontSize',14)
saveas(gcf,strcat(filename,'.png'))
