# Repository for the initiation of continuous integration

Application deployment project via a continuous integration chain.
My personal project is a text editor coded in c ++ with the Qt framework.

## Branches

* Master : default branch

## Folders

* text-editor : my personal project
* laravel-kingoludo : test project for gradle

## Todolist

- [ ] My project
	- [ ] : Create build.gradle
- [x] TP1 : git init
	- [x] Make a github repository
	- [x] Clone the repository in your local folder
	- [x] Create or Update the readme.md
- [x] TP2 : Gradle PHP Laravel
	- [x] Install docker and docker-compose
	- [x] Add project PHP Laravel from repository https://github.com/vanessakovalsky/laravel-kingoludo.git into your repository
	- [x] Build and run docker ``` docker build --tag my-gradle .gradle ```
	- [x] Create build.gradle in your project root
- [x] TP3 : Nexus
	- [x] Create the file docker-compose.yml and add it in the root folder
	- [x] Launch docker compose with : ``` docker-compose up -d ```
	- [x] Check for the launch of the 2 containers with ``` docker-compose ps ``` and check if nexus finished launching with ``` docker logs -f nexus ``` who show this line : ``` Started Sonatype Nexus OSS 3.23.0-03 ```
	- [x] Go to  http://localhost:8099 and connect with the login admin and the password we get from the commands ``` docker exec -t -i nexus sh ``` and ``` cat nexus-data/admin.password ```
	- [x] Run ``` docker network ls ``` and ``` docker network inspect ``` to get ip address of the network
	- [x] Add the file gradle.properties and add the publication in the build.gradle
	- [x] Launch the publication with ``` docker-compose up --build ```
- [x] TP4 : Test
	- [x] Specify the folder and the task test in build.gradle
		```
		task test(type:Exec, dependsOn: installDeps) {
  			//println 'Executing tests'
  			executable 'sh'
  			args '-c', "php \
   				'./project/vendor/phpunit/phpunit/phpunit' \
   				--configuration='./project/phpunit.xml' \
   				--log-junit='./logs/unitreport.xml'\
  				./project/tests"
		}
		```
- [x] TP5 : Jenkins
	- [x] Configure job in Jenkins
	- [x] Add git repository in job settings
	- [x] Add step of build in job settings
	- [ ] Configure project repository to automatic start build when new commit pushed
- [ ] TP6 : Quality
- [ ] TP7 : SonarQube
