create table Medico
(id_medico  number primary key,
 nome varchar2(15),
 crm varchar2(10));
 
create table Paciente
(id_paciente number primary key,
 nome varchar2(10),
 endereco varchar2(10));

create table Consulta
(id_consulta number,
 id_medico number,
 id_paciente number,
 data_hora date,
 constraint pk_consulta primary key(id_consulta));

create table especialidade
(id_especialidade number primary key,
nome varchar2(15));


create table medico_especialidade
(id_medico NUMBER,
 id_especialidade NUMBER,
 constraint pk_med_espec primary key(id_medico,id_especialidade) );


alter table consulta add constraint fk_id_medico foreign key(id_medico)references medico(id_medico);

alter table consulta add constraint fk_id_paciente foreign key(id_paciente) references paciente(id_paciente);

alter table medico_especialidade add 
(constraint fk_med_espec_id_medico foreign key(id_medico) references medico(id_medico),
constraint fk_med_espec_id_especialidade foreign key(id_especialidade) references especialidade);


create sequence s_especialidade nocache;
create sequence s_medico nocache  start with 100;
create sequence s_paciente nocache;
create sequence s_consulta start with 500 nocache;


insert into medico values(s_medico.nextval,'Pedro','12345');
insert into medico values(s_medico.nextval,'Ana','54647');
insert into medico values(s_medico.nextval,'Maria','5375');

insert into paciente values(s_paciente.nextval,'Ricardo','xxxx');
insert into paciente values(s_paciente.nextval,'Renato','yyyy');
insert into paciente values(s_paciente.nextval,'Cassia','zzzz');

insert into especialidade values(s_especialidade.nextval,'Cardiologista');
insert into especialidade values(s_especialidade.nextval,'Dermatologista');

select * from  especialidade;

insert into medico_especialidade values(100,1);
insert into medico_especialidade values(101,1);
insert into medico_especialidade values(102,2);

insert into consulta values(s_consulta.nextval,100,1,sysdate-20);
insert into consulta values(s_consulta.nextval,101,2,sysdate-10);
insert into consulta values(s_consulta.nextval,102,1,sysdate-5);

