# GITLAB

- [GITLAB](#gitlab)
- [Creating repository](#creating-repository)
- [Setting default branches](#setting-default-branches)
- [Creating an issue](#creating-an-issue)
- [Creating a branch for the issue](#creating-a-branch-for-the-issue)
- [Creating a merge request on the develop branch](#creating-a-merge-request-on-the-develop-branch)
- [Commenting and accepting the request](#commenting-and-accepting-the-request)
- [Creating a stable version](#creating-a-stable-version)
- [Working with wiki](#working-with-wiki)


# Creating repository 
To create a project in GitLab:

In your dashboard, click the green New project button or use the plus icon in the navigation bar. This opens the New project page.

On the New project page, choose if you want to:

Create a blank project.

Create a project using one of the available project templates.

Import a project from a different repository, if enabled on your GitLab instance. Contact your GitLab administrator if this is unavailable.

Run CI/CD pipelines for external repositories. 



***LOADING...***


# Setting default branches
in the GitLab Enterprise Edition 12.2.0-pre you have to use following: Setting → Repository → Default Branch ( expand it) and change the default branch Here

![day2_box](misc/images/2.1.png)

# Creating an issue
    When you create a new issue, you are prompted to fill in the data and fields of the issue, as illustrated below. If you know the values you want to assign to an issue, you can use the Quick actions feature to input values.

While creating an issue, you can associate it to an existing epic from current group by selecting it using Epic dropdown.
Accessing the New Issue form
There are many ways to get to the New Issue form from a project’s page:

Navigate to your Project’s Dashboard > Issues > New Issue:

![day2_box](misc/images/3.1.png)

From an open issue in your project, click the vertical ellipsis () button to open a dropdown menu, and then click New Issue to create a new issue in the same project:

![day2_box](misc/images/3.2.png)

From your Project’s Dashboard, click the plus sign (+) to open a dropdown menu with a few options. Select New Issue to create an issue in that project:

![day2_box](misc/images/3.3.png)

From an Issue Board, create a new issue by clicking on the plus sign (+) at the top of a list. It opens a new issue for that project, pre-labeled with its respective list.

![day2_box](misc/images/3.4.png)

# Creating a branch for the issue
When you try to create a new Branch from an issue using the "Create Branch" button, even though you type in the name of the source branch (or tag) you want to use, it doesn't consider the input and it always uses the default branch.
If you change, in the settings, the default branch, and create a branch using the "Create branch" button in an issue, it works fine.

go in the issue, find the "Create branch" button and click on the little arrow to expand the details

In the "Source (branch or tag)" Field, your default branch (Master in our example) will be pre-selected.

Change that entry to UAT (you'll have to type it in since there's no dropdown menu).
click on Create branch.

![day2_box](misc/images/4.1.png)

# Creating a merge request on the develop branch

Merge requests contain tabs at the top of the page to help you navigate to important parts of the merge request:

![day2_box](misc/images/5.1.png)

# Commenting and accepting the request

ou can add comments to a merge request diff. These comments persist, even when you:

Force-push after a rebase.

Amend a commit.

To add a commit diff comment:

1. To select a specific commit, on the merge request, select the Commits tab, select the commit message. To view the latest commit, select the Changes tab.

2. By the line you want to comment on, hover over the line number and select . You can select multiple lines by dragging the icon.

3. Type your comment and select Start a review or Add comment now.

The comment is displayed on the merge request’s Discussions tab.

The comment is not displayed on your project’s Repository > Commits page.

![day2_box](misc/images/6.1.png)

# Creating a stable version

1. Go to your repository

2. In the menu choose Repository > Tags

3. Add a tag for the version of your app. For example, v1.3.1.

4. Add a message (title) about the release. For example, Release 1.3.1.

5. Add a note that describes the details of the release. (Not optional. Adding a note to a tag is what makes it a release.)

6. Click Create tag.

![day2_box](misc/images/7.1.png)

# Working with wiki

1. Go to the project for which you want to create a wiki.

2. Click on the Wiki menu item.

![day2_box](misc/images/8.1.jpeg)

3. Click on the New Page button.

4. In the pop up, enter the name of the page; you can't use spaces in the name. Let's pick the name awesome-wiki.

5. When you click on the Build button, you will be redirected to the newly created wiki page. Here, you can add some content. After you're done adding content, you need to enter a commit message. For now, let's enter created first wiki page.

![day2_box](misc/images/8.2.jpeg)

6. Now, click on Create Page, and your wiki page will be created.