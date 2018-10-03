-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Окт 03 2018 г., 15:18
-- Версия сервера: 5.7.23
-- Версия PHP: 7.0.30-0+deb9u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `serials`
--

-- --------------------------------------------------------

--
-- Структура таблицы `adressbook`
--

CREATE TABLE `adressbook` (
  `ID` int(11) NOT NULL,
  `EName` varchar(50) NOT NULL,
  `EInfo` text NOT NULL,
  `Zk` tinyint(1) DEFAULT '0',
  `Th` tinyint(1) DEFAULT '0',
  `Mn` tinyint(1) DEFAULT '0',
  `Rp` tinyint(1) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `adressbook`
--

INSERT INTO `adressbook` (`ID`, `EName`, `EInfo`, `Zk`, `Th`, `Mn`, `Rp`) VALUES
(0, 'н.д.', '<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:\'MS Shell Dlg 2\'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">н.д.</p></body></html>', 1, 1, 1, 1),
(1, 'Днепр. ОДА', '<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:\'MS Shell Dlg 2\'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">г. Днепропетровск</p></body></html>', 1, 0, 0, NULL),
(2, 'Виконком Кр.Рогу', '<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:\'MS Shell Dlg 2\'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">г.Кривой Рог</p></body></html>', 1, 0, 0, 0);

-- --------------------------------------------------------

--
-- Структура таблицы `chanels`
--

CREATE TABLE `chanels` (
  `ID` int(11) NOT NULL,
  `type_id` int(11) NOT NULL,
  `chanel_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `chanels`
--

INSERT INTO `chanels` (`ID`, `type_id`, `chanel_name`) VALUES
(1, 1, 'CO'),
(2, 1, 'SO2'),
(3, 1, 'NO2'),
(7, 2, 'NO'),
(8, 2, 'SO2'),
(9, 2, 'NO2'),
(10, 3, 'H2S'),
(11, 3, 'NO'),
(12, 3, 'O3'),
(13, 4, 'PM2.5'),
(14, 4, 'PM10');

-- --------------------------------------------------------

--
-- Структура таблицы `device`
--

CREATE TABLE `device` (
  `ID` int(11) NOT NULL,
  `type_id` int(11) NOT NULL COMMENT 'Тип прибора',
  `rel_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'Дата выпуска',
  `serial` varchar(12) NOT NULL COMMENT 'Серийный номер',
  `id_zk` int(11) NOT NULL DEFAULT '0',
  `id_mn` int(11) NOT NULL DEFAULT '0',
  `id_th` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `device`
--

INSERT INTO `device` (`ID`, `type_id`, `rel_date`, `serial`, `id_zk`, `id_mn`, `id_th`) VALUES
(1, 1, '2018-10-02 21:00:00', '011-18', 2, 0, 0),
(2, 2, '2018-10-03 07:22:43', '012-18', 1, 0, 0),
(3, 4, '2018-10-03 08:14:32', '013-18', 2, 0, 0),
(4, 5, '2018-10-03 08:15:13', '001-18', 2, 0, 0),
(5, 5, '2018-10-03 11:45:00', '002-18', 1, 0, 0),
(6, 5, '2018-10-03 11:45:00', '003-18', 1, 0, 0);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `MN`
-- (See below for the actual view)
--
CREATE TABLE `MN` (
`ID` int(11)
,`EName` varchar(50)
,`EInfo` text
,`Zk` tinyint(1)
,`Th` tinyint(1)
,`Mn` tinyint(1)
,`Rp` tinyint(1)
);

-- --------------------------------------------------------

--
-- Структура таблицы `person`
--

CREATE TABLE `person` (
  `ID` int(11) NOT NULL,
  `PName` varchar(40) NOT NULL,
  `Post` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `person`
--

INSERT INTO `person` (`ID`, `PName`, `Post`) VALUES
(0, 'н.д.', 'н.д.'),
(1, 'Соловьев О.Л.', 'Метролог'),
(2, 'Погарелова В.В.', 'Снабженец');

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `RP`
-- (See below for the actual view)
--
CREATE TABLE `RP` (
`ID` int(11)
,`EName` varchar(50)
,`EInfo` text
,`Zk` tinyint(1)
,`Th` tinyint(1)
,`Mn` tinyint(1)
,`Rp` tinyint(1)
);

-- --------------------------------------------------------

--
-- Структура таблицы `stamp`
--

CREATE TABLE `stamp` (
  `ID` int(11) NOT NULL,
  `DateM` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `SSerial` varchar(6) NOT NULL,
  `IDs` int(11) NOT NULL,
  `IDp` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `stamp`
--

INSERT INTO `stamp` (`ID`, `DateM`, `SSerial`, `IDs`, `IDp`) VALUES
(1, '2018-10-03 05:00:00', '057603', 4, 1),
(2, '2018-10-03 11:46:06', '057604', 4, 0),
(3, '2018-10-03 11:46:06', '057605', 4, 0),
(4, '2018-10-03 11:49:44', '057609', 5, 2),
(5, '2018-10-03 11:49:44', '057610', 5, 2),
(6, '2018-10-03 11:49:44', '057611', 5, 2);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `TH`
-- (See below for the actual view)
--
CREATE TABLE `TH` (
`ID` int(11)
,`EName` varchar(50)
,`EInfo` text
,`Zk` tinyint(1)
,`Th` tinyint(1)
,`Mn` tinyint(1)
,`Rp` tinyint(1)
);

-- --------------------------------------------------------

--
-- Структура таблицы `types`
--

CREATE TABLE `types` (
  `ID` int(11) NOT NULL,
  `name_dev` varchar(40) NOT NULL COMMENT 'Имя устройства'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `types`
--

INSERT INTO `types` (`ID`, `name_dev`) VALUES
(1, 'GA-100(CO,SO2,NO2)'),
(2, 'GA-100(NO,SO2,NO2)'),
(3, 'GA-100(H2S,NO,O3)'),
(4, 'PM-100(2.5/10)'),
(5, 'МС-600');

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `ZK`
-- (See below for the actual view)
--
CREATE TABLE `ZK` (
`ID` int(11)
,`EName` varchar(50)
,`EInfo` text
,`Zk` tinyint(1)
,`Th` tinyint(1)
,`Mn` tinyint(1)
,`Rp` tinyint(1)
);

-- --------------------------------------------------------

--
-- Структура для представления `MN`
--
DROP TABLE IF EXISTS `MN`;

CREATE ALGORITHM=UNDEFINED DEFINER=`mishapk`@`%` SQL SECURITY DEFINER VIEW `MN`  AS  select `adressbook`.`ID` AS `ID`,`adressbook`.`EName` AS `EName`,`adressbook`.`EInfo` AS `EInfo`,`adressbook`.`Zk` AS `Zk`,`adressbook`.`Th` AS `Th`,`adressbook`.`Mn` AS `Mn`,`adressbook`.`Rp` AS `Rp` from `adressbook` where (`adressbook`.`Mn` = 1) ;

-- --------------------------------------------------------

--
-- Структура для представления `RP`
--
DROP TABLE IF EXISTS `RP`;

CREATE ALGORITHM=UNDEFINED DEFINER=`mishapk`@`%` SQL SECURITY DEFINER VIEW `RP`  AS  select `adressbook`.`ID` AS `ID`,`adressbook`.`EName` AS `EName`,`adressbook`.`EInfo` AS `EInfo`,`adressbook`.`Zk` AS `Zk`,`adressbook`.`Th` AS `Th`,`adressbook`.`Mn` AS `Mn`,`adressbook`.`Rp` AS `Rp` from `adressbook` where (`adressbook`.`Rp` = 1) ;

-- --------------------------------------------------------

--
-- Структура для представления `TH`
--
DROP TABLE IF EXISTS `TH`;

CREATE ALGORITHM=UNDEFINED DEFINER=`mishapk`@`%` SQL SECURITY DEFINER VIEW `TH`  AS  select `adressbook`.`ID` AS `ID`,`adressbook`.`EName` AS `EName`,`adressbook`.`EInfo` AS `EInfo`,`adressbook`.`Zk` AS `Zk`,`adressbook`.`Th` AS `Th`,`adressbook`.`Mn` AS `Mn`,`adressbook`.`Rp` AS `Rp` from `adressbook` where (`adressbook`.`Th` = 1) ;

-- --------------------------------------------------------

--
-- Структура для представления `ZK`
--
DROP TABLE IF EXISTS `ZK`;

CREATE ALGORITHM=UNDEFINED DEFINER=`mishapk`@`%` SQL SECURITY DEFINER VIEW `ZK`  AS  select `adressbook`.`ID` AS `ID`,`adressbook`.`EName` AS `EName`,`adressbook`.`EInfo` AS `EInfo`,`adressbook`.`Zk` AS `Zk`,`adressbook`.`Th` AS `Th`,`adressbook`.`Mn` AS `Mn`,`adressbook`.`Rp` AS `Rp` from `adressbook` where (`adressbook`.`Zk` = 1) ;

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `adressbook`
--
ALTER TABLE `adressbook`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `chanels`
--
ALTER TABLE `chanels`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`,`type_id`),
  ADD KEY `ID_2` (`ID`,`type_id`),
  ADD KEY `type_id` (`type_id`);

--
-- Индексы таблицы `device`
--
ALTER TABLE `device`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`),
  ADD KEY `type_id` (`type_id`),
  ADD KEY `id_zk` (`id_zk`),
  ADD KEY `id_mn` (`id_mn`,`id_th`);

--
-- Индексы таблицы `person`
--
ALTER TABLE `person`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `stamp`
--
ALTER TABLE `stamp`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `IDs` (`IDs`,`IDp`),
  ADD KEY `IDp` (`IDp`);

--
-- Индексы таблицы `types`
--
ALTER TABLE `types`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `ID` (`ID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `adressbook`
--
ALTER TABLE `adressbook`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT для таблицы `chanels`
--
ALTER TABLE `chanels`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
--
-- AUTO_INCREMENT для таблицы `device`
--
ALTER TABLE `device`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT для таблицы `person`
--
ALTER TABLE `person`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT для таблицы `stamp`
--
ALTER TABLE `stamp`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT для таблицы `types`
--
ALTER TABLE `types`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `chanels`
--
ALTER TABLE `chanels`
  ADD CONSTRAINT `chanels_ibfk_1` FOREIGN KEY (`type_id`) REFERENCES `types` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `device`
--
ALTER TABLE `device`
  ADD CONSTRAINT `device_ibfk_1` FOREIGN KEY (`type_id`) REFERENCES `types` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `stamp`
--
ALTER TABLE `stamp`
  ADD CONSTRAINT `stamp_ibfk_1` FOREIGN KEY (`IDs`) REFERENCES `device` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `stamp_ibfk_2` FOREIGN KEY (`IDp`) REFERENCES `person` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
