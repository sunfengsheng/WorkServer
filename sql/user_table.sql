CREATE TABLE user_info(
    `Id` int(11) NOT NULL,
    `WXId` varchar(255) NOT NULL,
    `Name` varchar(255) NULL,
    `PhoneNum` int(11) NULL,
    `AttentionCount` int(11) NOT NULL,
    `LikeCount` int(11) NOT NULL,
    `CollectWorkIds` varchar(255) NULL,  
PRIMARY KEY (`Id`)
);
alter table user_info modify Id int auto_increment;

CREATE TABLE user_works(
    `Id` int(11) NOT NULL,
    `Title` varchar(255) NOT NULL,
    `Content` varchar(255) NULL,
    `ImageIds` varchar(255) NULL,
    `ReviewIds` varchar(255) NULL,
PRIMARY KEY (`Id`)
);
alter table user_works modify Id int auto_increment;

CREATE TABLE user_image(
    `Id` int(11) NOT NULL,
    `ImagePath` varchar(255) NOT NULL,
PRIMARY KEY (`Id`)
);
alter table user_image modify Id int auto_increment;

CREATE TABLE user_review(
    `Id` int(11) NOT NULL,
    `Review` varchar(255) NOT NULL,
PRIMARY KEY (`Id`)
);
alter table user_review modify Id int auto_increment;

