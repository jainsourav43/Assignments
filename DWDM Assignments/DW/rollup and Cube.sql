--create table student( name varchar(20), sex varchar(7), marks number(10,2)
--);
--create table department( name varchar(20),deptid number(2), YOE number(5)
--);
--alter table student add constraints name as primary key;
--insert into student values('&Enter_Name','&Enter_Sex',&Enter_Marks,'&Enter_DEPT');
--insert into department values('&Name',&Enter,&enter);
--
--select department,name,sex , avg(marks)
--from student 
--where  deptartment= 'CSE'
--group by grouping sets ((sex ,name),(department ,sex))  ;
--select department,sex,marks,name
--from student 
--group by  rollup(department,sex,marks,name) ;
--
--alter table student add  department varchar(20);
--ALTER TABLE student ADD CONSTRAINT student_fk
--FOREIGN KEY (department) REFERENCES dapartment (name);
--
select department, grouping_id (sex) ,group_id(), avg(marks)
from student 
WHERE sex='M'
group by   department , cube(sex,name) ;
--grouping sex ;

--create table employee(
--name varchar(20),
--rank varchar(10),
--salary number(10),
--division_name varchar(10)
--);
--
--create table organisation (
--division_name varchar(20),
--division_id number(20),
--no_of_employee number(20)
--
--);
--
--
--alter table "ORGANISATION" add constraint  primary key("")
--alter table organisation add constraint primary key (division_id);


--alter table employee add constraint student_fk 
--foreign key (division_name) references organisation (division_name);
